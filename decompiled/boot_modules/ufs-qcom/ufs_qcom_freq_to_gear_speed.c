__int64 __fastcall ufs_qcom_freq_to_gear_speed(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w9

  if ( a2 <= 149999999 )
  {
    if ( a2 != 37500000 && a2 != 75000000 )
    {
      if ( a2 != 100000000 )
        goto LABEL_18;
LABEL_9:
      v2 = 2;
      goto LABEL_15;
    }
    v2 = 1;
  }
  else
  {
    if ( a2 <= 299999999 )
    {
      if ( a2 != 150000000 )
      {
        if ( a2 == 201500000 )
        {
          v2 = 3;
          goto LABEL_15;
        }
LABEL_18:
        dev_err(*(_QWORD *)(a1 + 64), "%s: Unsupported clock freq : %lu\n", "ufs_qcom_freq_to_gear_speed", a2);
        return 0;
      }
      goto LABEL_9;
    }
    if ( a2 == 403000000 )
    {
      v2 = 5;
    }
    else
    {
      if ( a2 != 300000000 )
        goto LABEL_18;
      v2 = 4;
    }
  }
LABEL_15:
  v3 = *(_DWORD *)(a1 + 2724);
  if ( v2 >= v3 )
    return v3;
  else
    return v2;
}
