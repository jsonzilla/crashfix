# Remeber

To update the documentation, you need to run the following command:

```bash
doxygen Doxyfile
```

And move the generated files to the `docs/doc` folder.
```bash
mv ./html/* ../docs/doc
mv ./footer.html ../docs/doc
mv ./header.html ../docs/doc
mv ./logo.png ../docs/doc
mv ./style.css ../docs/doc
mv ./html/image/* ../docs/doc/image
mv ./favicon.ico ../docs/doc/favicon.ico
```