__int64 __fastcall hdcp2_feature_supported_smcinvoke(__int64 a1)
{
  __int64 v3; // x0
  _DWORD *v4; // x8
  unsigned int v5; // w20

  if ( !a1 )
  {
    printk(&unk_CF99);
    return 0;
  }
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 )
    return 1;
  if ( (unsigned int)hdcp2_app_load_0(a1) )
    return 0;
  if ( (*(_BYTE *)(a1 + 48) & 1) != 0 )
  {
    v4 = *(_DWORD **)(a1 + 56);
    v3 = *(_QWORD *)(a1 + 64);
    v5 = 1;
    if ( *(v4 - 1) != 816020464 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v4)(v3, 1, 0, 0) )
    {
      printk(&unk_C023);
      v5 = 0;
    }
    else
    {
      *(_BYTE *)(a1 + 44) = 1;
    }
  }
  else
  {
    printk(&unk_C830);
    v5 = 0;
  }
  hdcp2_app_unload_0(a1);
  return v5;
}
