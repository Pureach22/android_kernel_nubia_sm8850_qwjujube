__int64 __fastcall hdcp1_feature_supported_smcinvoke(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  _DWORD *v4; // x9
  int v5; // w0
  _BOOL4 v6; // w21
  int v7; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v8[3]; // [xsp+8h] [xbp-18h] BYREF

  v8[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    printk(&unk_C81E);
    goto LABEL_12;
  }
  if ( (*(_BYTE *)(a1 + 64) & 1) != 0 )
  {
    result = 1;
    goto LABEL_13;
  }
  if ( (unsigned int)hdcp1_app_load_0(a1) || (*(_BYTE *)(a1 + 72) & 1) == 0 )
  {
LABEL_12:
    result = 0;
    goto LABEL_13;
  }
  v4 = *(_DWORD **)a1;
  v3 = *(_QWORD *)(a1 + 8);
  v7 = 1;
  v8[0] = &v7;
  v8[1] = 4;
  if ( *(v4 - 1) != 816020464 )
    __break(0x8229u);
  v5 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v4)(v3, 1, v8, 1);
  v6 = v5 == 0;
  if ( v5 )
    printk(&unk_CEDF);
  else
    *(_BYTE *)(a1 + 64) = 1;
  hdcp1_app_unload_0(a1);
  result = v6;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
