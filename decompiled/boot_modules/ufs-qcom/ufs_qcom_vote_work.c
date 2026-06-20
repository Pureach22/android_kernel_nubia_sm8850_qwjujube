__int64 __fastcall ufs_qcom_vote_work(__int64 result)
{
  unsigned int v1; // w20
  __int64 v2; // x21
  __int64 v3; // x19
  char v4; // w8
  int v5; // w9
  __int64 v6; // x8
  unsigned __int64 v7; // x23
  unsigned __int64 v8; // x8
  bool v9; // cf

  v1 = **(_DWORD **)(result - 24);
  if ( *(_DWORD *)(result + 40) != v1 )
  {
    v2 = *(_QWORD *)(result - 16);
    v3 = result;
    v4 = 0;
    while ( 1 )
    {
      v5 = *(_DWORD *)(v3 - 32);
      v6 = -1LL << v4;
      v7 = (unsigned int)v6 & v5;
      if ( ((unsigned int)v6 & v5) == 0 )
      {
LABEL_7:
        *(_DWORD *)(v3 + 40) = v1;
        *(_BYTE *)(v3 - 8) = 1;
        return result;
      }
      result = dev_pm_qos_update_request(v2, v1);
      if ( (result & 0x80000000) != 0 )
        return dev_err(
                 *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 32) + 16LL) + 64LL),
                 "%s: update qos - failed: %d\n",
                 "ufs_qcom_vote_work",
                 result);
      v2 += 80;
      v8 = __clz(__rbit64(v7));
      v9 = v8 >= 0x1F;
      v4 = v8 + 1;
      if ( v9 )
        goto LABEL_7;
    }
  }
  return result;
}
