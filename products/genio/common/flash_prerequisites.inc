This section provides step-by-step instructions for preparing your development host for flashing the image to the device.

.. note::

    The following instructions assume you are using Ubuntu 22.04 LTS.

Create udev Rules
-----------------

To enable USB device access for your user account, create new udev rules, reload the udev rules, and trigger them.

.. code-block::

    echo -n 'SUBSYSTEM=="usb", ATTR{idVendor}=="0e8d", ATTR{idProduct}=="201c", MODE="0660", TAG+="uaccess" SUBSYSTEM=="usb", ATTR{idVendor}=="0e8d", ATTR{idProduct}=="0003", MODE="0660", TAG+="uaccess" SUBSYSTEM=="usb", ATTR{idVendor}=="0403", MODE="0660", TAG+="uaccess" SUBSYSTEM=="gpio", MODE="0660", TAG+="uaccess"' | sudo tee /etc/udev/rules.d/72-aiot.rules
    sudo udevadm control --reload-rules
    sudo udevadm trigger

Enable UART Access
------------------

Your user account must be in the ``dialout`` group to access UART devices. Check your group memberships.

.. code-block::

    groups


If ``dialout`` is not listed, add your user to the group.

.. code-block::

    sudo usermod -a -G dialout $USER

.. note::

    You must log out and log back in for the new group membership to take effect.

Install ``minicom``
-------------------

Install the ``minicom`` terminal program.

.. code-block::

    sudo apt install minicom

Install ``genio-tools``
-----------------------

Install the ``genio-tools`` package using pip and verify the installation.

.. code-block::

    pip3 install -U genio-tools

.. code-block::

    genio-config
