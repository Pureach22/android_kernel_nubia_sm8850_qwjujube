__int64 __fastcall qcom_dcvs_kobject_get(unsigned int a1)
{
  __int64 v2; // x8
  __int64 v3; // x8

  if ( a1 > 5 )
    return -22;
  v2 = dcvs_data;
  if ( *(_BYTE *)(dcvs_data + 144) != 1 )
    return -517;
  if ( a1 != 5 )
  {
    v3 = *(_QWORD *)(dcvs_data + 8LL * a1 + 96);
    if ( !v3 )
      return -19;
    v2 = v3 + 8;
  }
  if ( (*(_BYTE *)(v2 + 60) & 1) != 0 )
    return v2;
  else
    return -19;
}
