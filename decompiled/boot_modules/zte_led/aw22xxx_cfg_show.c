size_t __fastcall aw22xxx_cfg_show(__int64 a1, int a2, char *s)
{
  __int64 v4; // x3

  v4 = *(unsigned int *)(*(_QWORD *)(a1 + 152) + 752LL);
  if ( (unsigned int)v4 > 0xA )
  {
    printk(&unk_137D3, "aw22xxx_cfg_show");
  }
  else if ( (unsigned int)snprintf(s, 0x1000u, "current cfg = %s\n", *(const char **)(aw22xxx_cfg_name + 8 * v4)) > 0xFFF )
  {
    return -14;
  }
  return strlen(s);
}
