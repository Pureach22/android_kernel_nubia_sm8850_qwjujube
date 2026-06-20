__int64 __fastcall show_cur_freq(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x10
  int v6; // w11
  _DWORD *v7; // x10
  __int64 v8; // x0
  int v9; // w0
  __int64 result; // x0
  int v11; // w20
  _DWORD v12[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 80);
  v12[2] = 0;
  if ( (*(_BYTE *)(v3 + 28) & 1) != 0 )
  {
    v4 = *(_QWORD *)(memlat_data + 312);
    if ( !v4 )
    {
      result = -19;
      goto LABEL_9;
    }
    v6 = *(_DWORD *)(a1 + 100);
    v7 = *(_DWORD **)(v4 + 8);
    v8 = *(_QWORD *)(memlat_data + 320);
    v12[0] = *(_DWORD *)(v3 + 16);
    v12[1] = v6;
    if ( *(v7 - 1) != 1134762728 )
      __break(0x822Au);
    v9 = ((__int64 (__fastcall *)(__int64, _DWORD *, __int64, __int64, __int64, __int64))v7)(
           v8,
           v12,
           0x4D454D4C4154LL,
           35,
           12,
           4);
    if ( v9 < 0 )
    {
      v11 = v9;
      printk(&unk_CAEB);
      result = v11;
      goto LABEL_9;
    }
    LODWORD(result) = scnprintf(a3, 4096, "%u\n", v12[0]);
  }
  else
  {
    LODWORD(result) = scnprintf(a3, 4096, "%u\n", *(unsigned int *)(a1 - 4));
  }
  result = (int)result;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
