__int64 __fastcall enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  unsigned int v7; // w0
  unsigned int v8; // w21
  unsigned int v9; // w0
  const char *v11; // x2
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12[0] = 0;
  v6 = kstrtobool(a3, v12);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else if ( *(unsigned __int8 *)(v5 + 226) == v12[0] )
  {
    if ( v12[0] )
      v11 = "enabled";
    else
      v11 = "disabled";
    dev_err(*(_QWORD *)(v5 + 8), "AMOLED ECM is already %s\n", v11);
    a4 = -22;
  }
  else if ( v12[0] )
  {
    v7 = amoled_ecm_enable(v5);
    if ( (v7 & 0x80000000) != 0 )
    {
      v8 = v7;
      dev_err(*(_QWORD *)(v5 + 8), "Failed to enable AMOLED ECM, rc=%d\n", v7);
LABEL_15:
      a4 = (int)v8;
    }
  }
  else
  {
    v9 = amoled_ecm_disable((_QWORD *)v5);
    if ( (v9 & 0x80000000) != 0 )
    {
      v8 = v9;
      dev_err(*(_QWORD *)(v5 + 8), "Failed to disable AMOLED ECM, rc=%d\n", v9);
      goto LABEL_15;
    }
    *(_WORD *)(v5 + 32) = 0;
    *(_DWORD *)(v5 + 28) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
