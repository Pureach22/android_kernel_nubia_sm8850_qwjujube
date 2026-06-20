__int64 __fastcall ufs_qcom_is_genpd_supported(__int64 a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  bool v7; // cf

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 64);
    result = 0;
    v4 = *(_QWORD *)(v1 + 592);
    if ( v4 )
    {
      if ( v4 <= 0xFFFFFFFFFFFFF000LL )
      {
        result = 0;
        v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 184) + 8LL) + 96LL);
        if ( v5 )
        {
          if ( v5 <= 0xFFFFFFFFFFFFF000LL )
          {
            v6 = *(_QWORD *)(v5 + 592);
            if ( v6 )
              v7 = v6 >= 0xFFFFFFFFFFFFF001LL;
            else
              v7 = 1;
            return !v7;
          }
        }
      }
    }
  }
  else
  {
    __break(0x800u);
    return ufs_qcom_get_device_id(0);
  }
  return result;
}
