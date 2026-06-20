__int64 __fastcall ufs_qcom_save_host_ptr(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  if ( result )
  {
    if ( *(_QWORD *)(*(_QWORD *)(result + 64) + 744LL) )
    {
      v1 = result;
      v2 = *(_QWORD *)(result + 184);
      result = of_alias_get_id(*(_QWORD *)(*(_QWORD *)(result + 64) + 744LL), "ufshc");
      if ( (int)result <= 0 )
      {
        return dev_err(*(_QWORD *)(v1 + 64), "Failed to get host index %d\n", (unsigned int)result);
      }
      else if ( (unsigned int)result > 2 )
      {
        return dev_err(*(_QWORD *)(v1 + 64), "invalid host index %d\n", (unsigned int)result);
      }
      else
      {
        ufs_qcom_hosts[(unsigned int)(result - 1)] = v2;
      }
    }
  }
  else
  {
    __break(0x800u);
    return ufs_qcom_populate_cluster_info(result);
  }
  return result;
}
