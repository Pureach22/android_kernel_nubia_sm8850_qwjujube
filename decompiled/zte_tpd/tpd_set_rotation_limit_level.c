__int64 __fastcall tpd_set_rotation_limit_level(__int64 a1, int a2, __int64 a3)
{
  _QWORD *v4; // x19
  __int64 v6; // x9
  __int64 v7; // x2
  int v8; // w8
  int v9; // w9
  __int64 result; // x0
  void *v11; // x0

  v4 = *(_QWORD **)(a1 + 3072);
  printk(&unk_34878, "tpd_set_rotation_limit_level", a3);
  if ( !v4 )
    return 4294967274LL;
  v6 = v4[78];
  if ( *(_DWORD *)(v6 + 184) && (*(_BYTE *)(v6 + 188) & 1) != 0 )
    v7 = 0;
  else
    v7 = *(unsigned int *)(*v4 + 524LL);
  v8 = *((_DWORD *)v4 + 351);
  if ( a2 >= 3 )
    v9 = 3;
  else
    v9 = a2;
  *((_DWORD *)v4 + 387) = v9;
  if ( v8 != 1 )
  {
    v11 = &unk_3B5E0;
    goto LABEL_15;
  }
  result = syna_dev_set_display_rotation(v4, *(_DWORD *)(a1 + 16), v7);
  if ( (_DWORD)result )
  {
    v11 = &unk_3220D;
LABEL_15:
    printk(v11, "tpd_set_rotation_limit_level", v7);
    return 0;
  }
  return result;
}
