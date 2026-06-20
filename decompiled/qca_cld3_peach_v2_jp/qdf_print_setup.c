__int64 qdf_print_setup()
{
  __int64 v0; // x20
  char *v1; // x23

  v0 = -12544;
  do
  {
    v1 = (char *)&print_ctrl_obj + v0;
    memset((char *)&print_ctrl_obj + v0 + 12576, 0, 0x14Eu);
    v0 += 392;
    *((_QWORD *)v1 + 1614) = 0;
    *((_QWORD *)v1 + 1615) = 0;
    v1[12928] = 0;
  }
  while ( v0 );
  return 0;
}
