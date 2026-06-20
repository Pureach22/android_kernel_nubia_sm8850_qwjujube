char *cnss_plat_ipc_qmi_daemon_config()
{
  char *v0; // x19
  unsigned int v1; // w20

  if ( byte_7DDC != 1 )
    return nullptr;
  v0 = &daemon_cfg;
  if ( daemon_cfg != 1 )
  {
    v1 = 0;
    do
    {
      msleep(50);
      if ( v1 > 0xC6 )
        break;
      ++v1;
    }
    while ( daemon_cfg != 1 );
  }
  return v0;
}
