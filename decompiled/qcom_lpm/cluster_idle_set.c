__int64 __fastcall cluster_idle_set(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x8
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  if ( (unsigned int)kstrtobool(a3, v8) )
  {
    a4 = -22;
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return a4;
  }
  v6 = *(unsigned int *)(a2 - 8);
  if ( (unsigned int)v6 < 4 )
  {
    *(_BYTE *)(*(_QWORD *)(a2 - 24) + v6 + 376) = v8[0] ^ 1;
    goto LABEL_5;
  }
  __break(0x5512u);
  return sleep_disabled_show();
}
