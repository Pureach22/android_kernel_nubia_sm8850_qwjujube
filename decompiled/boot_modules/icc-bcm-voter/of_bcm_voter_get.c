__int64 __fastcall of_bcm_voter_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  __int64 v4; // x4
  void *v5; // x19
  _UNKNOWN **v6; // x9
  __int64 v7; // x19
  _QWORD v8[11]; // [xsp+8h] [xbp-58h] BYREF

  v8[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v2 = *(_QWORD *)(a1 + 744)) == 0 )
  {
    result = -19;
    goto LABEL_17;
  }
  if ( a2 )
  {
    LODWORD(result) = of_property_match_string(*(_QWORD *)(a1 + 744), "qcom,bcm-voter-names", a2);
    v4 = (unsigned int)result;
    if ( (result & 0x80000000) != 0 )
    {
      result = (int)result;
      goto LABEL_17;
    }
  }
  else
  {
    v4 = 0;
  }
  memset(v8, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v2, "qcom,bcm-voters", 0, 0, v4, v8) )
    v5 = nullptr;
  else
    v5 = (void *)v8[0];
  mutex_lock(&bcm_voter_lock);
  v6 = &bcm_voters;
  while ( 1 )
  {
    v6 = (_UNKNOWN **)*v6;
    if ( v6 == &bcm_voters )
      break;
    if ( *(v6 - 12) == v5 )
    {
      v7 = (__int64)(v6 - 13);
      goto LABEL_16;
    }
  }
  v7 = -517;
LABEL_16:
  mutex_unlock(&bcm_voter_lock);
  result = v7;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
