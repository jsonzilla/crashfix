//! \file PdbSymLexicalScope.cpp
//! \brief Symbol lexical scope.
//! \author Oleg Krivtsov
//! \date 2011

#include "stdafx.h"
#include "PdbSymLexicalScope.h"
#include "PdbSymbol.h"

//---------------------------------------------------------------
// CPdbSymLexicalScope implementation
//---------------------------------------------------------------

CPdbSymLexicalScope::CPdbSymLexicalScope(DWORD dwScopeId, CPdbSymLexicalScope* pParentScope)
{
    m_dwScopeId = dwScopeId;
    m_pParentScope = pParentScope;
}

CPdbSymLexicalScope::~CPdbSymLexicalScope()
{
    // Remove child scopes
	for (auto&& it : m_apChildScopes){
        delete it.second;
	}
}

DWORD CPdbSymLexicalScope::GetLexicalScopeId() const
{
    return m_dwScopeId;
}

CPdbSymLexicalScope*CPdbSymLexicalScope::GetParentLexicalScope() const
{
    return m_pParentScope;
}

UINT CPdbSymLexicalScope::GetChildScopeCount() const
{
    // Get children count
    return (UINT)m_apChildScopes.size();
}

CPdbSymLexicalScope*CPdbSymLexicalScope::GetChildScope(int nIndex)
{
    if(nIndex<0 || nIndex>=(int)m_apChildScopes.size())
        return nullptr; // Invalid parameter

    // Get lexical scope by its index
    return m_apChildScopes[nIndex];
}

void CPdbSymLexicalScope::AddChildScope(CPdbSymLexicalScope* const pChild)
{
    m_apChildScopes[pChild->GetLexicalScopeId()] = pChild;
}

UINT CPdbSymLexicalScope::GetSymbolCount() const
{
    return (UINT)m_apSymbols.size();
}

CPdbSymbol*CPdbSymLexicalScope::GetSymbol(int nIndex)
{
    if(nIndex<0 || nIndex>=(int)m_apSymbols.size())
        return nullptr; // Invalid index

    return m_apSymbols[nIndex];
}

void CPdbSymLexicalScope::AddSymbol(CPdbSymbol* pSymbol)
{
    pSymbol->SetLexicalScope(this);
    m_apSymbols.push_back(pSymbol);
}
