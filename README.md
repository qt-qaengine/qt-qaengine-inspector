# qainspector

## prepare

```
sudo add-apt-repository ppa:alexlarsson/flatpak
sudo apt install flatpak flatpak-builder

flatpak remote-add --user --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
flatpak install --user flathub org.kde.Sdk/x86_64/5.11 org.kde.Platform/x86_64/5.11
```

## build

```
flatpak-builder --user --install-deps-from=flathub --force-clean --repo=repo build ru.qaengine.qainspector.json
flatpak build-bundle --runtime-repo=https://flathub.org/repo/flathub.flatpakrepo $(pwd)/repo ru.qaengine.qainspector.flatpak ru.qaengine.qainspector stable
```

## install

```
flatpak --user install ru.qaengine.qainspectorqa insqa.flatpak
```

## run

```
flatpak run ru.qaengine.qainspector
```


