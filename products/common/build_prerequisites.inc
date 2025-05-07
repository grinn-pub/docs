Before building the image, you must set up your development environment with the necessary tools and system resources. 
This section outlines the required system specifications and installation steps for essential tools.

System Requirements
-------------------

To successfully build the image, ensure your system meets the following requirements:

- A Linux host system (Ubuntu 22.04 recommended)
- Minimum 200 GiB of free disk space
- At least 16 GiB of RAM
- Internet connection

Install the ``repo`` Tool
----------------------------

Follow these steps to install the ``repo`` tool in your local ``~/bin`` directory:

.. code-block:: console

   mkdir -p ~/bin
   PATH="${HOME}/bin:${PATH}"
   curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
   chmod a+rx ~/bin/repo

This ensures the ``repo`` command is available in your shell environment.

Install the ``docker`` Tool
------------------------------

The installation process varies depending on your operating system. 
To install the ``docker`` tool, follow instructions from the `official Docker website <https://docs.docker.com/engine/install/>`_.