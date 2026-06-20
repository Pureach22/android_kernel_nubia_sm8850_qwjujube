__int64 __fastcall status_show(__int64 a1)
{
  const char **v2; // x23
  const char *v3; // x21
  int v4; // w9
  __int64 v5; // x0
  unsigned int v6; // w0
  __int64 v7; // x2
  __int64 v8; // x24
  unsigned int v9; // w9
  char v10; // w8
  const char *v11; // x26
  const char *v12; // x21
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x20
  __int64 result; // x0
  unsigned int v16; // w19
  int v17; // [xsp+4h] [xbp-1Ch]
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  int v19; // [xsp+10h] [xbp-10h]
  int v20; // [xsp+14h] [xbp-Ch]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(const char ***)(a1 + 128);
  v18 = 0x10000800DLL;
  v3 = v2[2];
  v4 = *((_DWORD *)v2 + 2);
  v19 = 23;
  v20 = v4;
  mutex_lock(v3 + 16);
  v5 = *((_QWORD *)v3 + 1);
  *((_DWORD *)v3 + 16) = 0;
  v6 = pmic_glink_write(v5, &v18, 16);
  if ( v6 )
  {
    v16 = v6;
LABEL_14:
    mutex_unlock(v3 + 16);
    printk(&unk_798A, "status_show", *v2);
    result = v16;
    goto LABEL_11;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v3 + 64, 250) )
  {
    printk(&unk_750C, "battery_dbg_write", v7);
    v16 = -110;
    goto LABEL_14;
  }
  mutex_unlock(v3 + 16);
  v8 = *((unsigned int *)v2 + 48);
  if ( (_DWORD)v8 )
  {
    v9 = *((_DWORD *)v2 + 49);
    if ( v9 >= 0x21 )
    {
      __break(0x5512u);
      JUMPOUT(0x73B0);
    }
    v10 = 0;
    v11 = v3 + 4384;
    v12 = &v3[12 * v9 + 4384];
    v17 = *((_DWORD *)v2 + 7);
    do
    {
      v13 = (-1LL << v10) & v8;
      if ( !v13 )
        break;
      v14 = __clz(__rbit64(v13));
      seq_printf(
        a1,
        "           %-*s: %-*s: %d\n",
        12,
        *v2,
        12,
        &v11[12 * (unsigned int)v14],
        *((_DWORD *)v2 + v14 + 16));
      v10 = v14 + 1;
    }
    while ( v14 < 0x1F );
    seq_printf(a1, "EFFECTIVE: %-*s: %-*s: %d\n", 12, *v2, 12, v12, v17);
  }
  else
  {
    seq_putc(a1, 10);
  }
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
