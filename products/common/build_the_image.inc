This section provides step-by-step instructions for setting up the workspace, starting the containerized build environment,
preparing the Yocto configuration, and starting the image build process.

Initialize the Workspace
------------------------

Create a new directory for the build environment and initialize ``repo`` with the appropriate manifest.
This will download the necessary layers for the build.

.. parsed-literal::

    mkdir |PRODUCT_FAMILY|
    cd |PRODUCT_FAMILY|
    repo init -u https\://github.com/grinn-global/manifest-grinn-|PRODUCT_FAMILY|.git -b kirkstone
    repo sync

Run the Docker Container
------------------------

Start the Grinn Yocto Docker container, mounting the current working directory into the container and mapping your user ID.

.. code-block::

    docker run -it \
        -e CUSTOM_UID=$(id -u) \
        -e CUSTOM_GID=$(id -g) \
        -v $(pwd):$(pwd) \
        -w $(pwd) \
        ghcr.io/grinn-global/grinn-yocto-container


Configure the Build Environment
-------------------------------

Set the ``TEMPLATECONF`` environment variable and source the Yocto environment script.

.. parsed-literal::

    export TEMPLATECONF=$(pwd)/src/meta-grinn-|PRODUCT_FAMILY|/conf/templates/default
    source src/poky/oe-init-build-env


Build the Image
-------------------

Set the ``MACHINE`` variable to specify the target hardware platform. Then run ``bitbake`` to build the image.

.. parsed-literal::

    export MACHINE=\ |MACHINE|
    bitbake |IMAGE|

.. note::

    The build process may take a while, depending on your system's resources.

After the build completes, verify that the image was created by checking the output directory.

.. parsed-literal::

    ls tmp/deploy/images/|MACHINE|
