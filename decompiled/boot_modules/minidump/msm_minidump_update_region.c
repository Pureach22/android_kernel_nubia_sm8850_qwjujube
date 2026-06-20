__int64 __fastcall msm_minidump_update_region(int a1, char *string)
{
  unsigned __int8 v3; // w8
  __int64 result; // x0
  size_t v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x0

  v3 = atomic_load((unsigned __int8 *)&md_init_done);
  result = 4294967274LL;
  if ( !string || (v3 & 1) == 0 )
    return result;
  v6 = strnlen(string, 0xDu);
  if ( v6 >= 0xE )
  {
    v6 = _fortify_panic(2, 13, v6 + 1);
    goto LABEL_16;
  }
  if ( v6 == 13 )
  {
LABEL_16:
    v8 = _fortify_panic(4, 13, v6 + 1);
    return msm_minidump_add_region(v8);
  }
  if ( !*((_QWORD *)string + 3) || (string[40] & 3) != 0 )
  {
    printk_deferred("Invalid entry details\n");
    return 4294967274LL;
  }
  if ( a1 > 200 || !md_core_0 )
    return 4294967274LL;
  v7 = *(_DWORD **)(md_core_0 + 40);
  if ( *(v7 - 1) != -2123449340 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(_QWORD, char *))v7)((unsigned int)a1, string);
}
