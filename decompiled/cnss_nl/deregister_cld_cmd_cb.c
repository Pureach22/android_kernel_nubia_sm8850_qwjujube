__int64 __fastcall deregister_cld_cmd_cb(unsigned __int8 a1)
{
  char *v2; // x8

  if ( (unsigned int)a1 - 41 < 0xFFFFFFD8 )
    return 4294967274LL;
  v2 = (char *)&nl_data + 16 * a1;
  *((_QWORD *)v2 - 2) = 0;
  *((_QWORD *)v2 - 1) = 0;
  return 0;
}
