__int64 __fastcall sde_kms_set_lutdma_vbif_remap(__int64 result)
{
  __int64 v1; // x8
  _DWORD *v2; // x8
  int v3; // [xsp+4h] [xbp-1Ch]
  int v4; // [xsp+8h] [xbp-18h]
  int v5; // [xsp+Ch] [xbp-14h]
  int v6; // [xsp+10h] [xbp-10h]
  int v7; // [xsp+14h] [xbp-Ch]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 152);
  if ( v1 )
  {
    v2 = (_DWORD *)(v1 + 0x4000);
    v6 = 0;
    v3 = v2[892];
    v4 = v2[891];
    LODWORD(v2) = v2[894];
    v7 = 3;
    v5 = (int)v2;
    result = sde_vbif_set_qos_remap();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
