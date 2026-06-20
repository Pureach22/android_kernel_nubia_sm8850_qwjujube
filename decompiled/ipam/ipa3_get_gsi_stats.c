__int64 __fastcall ipa3_get_gsi_stats(__int64 result, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x8
  int v4; // w4
  __int64 v5; // x0

  if ( (int)result > 5 )
  {
    if ( (int)result > 8 )
    {
      if ( (_DWORD)result == 9 )
      {
        *(_BYTE *)(a2 + 200) = 2;
        return ipa3_get_rtk_gsi_stats(a2);
      }
      if ( (_DWORD)result == 10 )
      {
        *(_BYTE *)(a2 + 200) = 2;
        return ipa3_get_ntn_gsi_stats((_DWORD *)a2);
      }
    }
    else
    {
      if ( (_DWORD)result == 6 )
      {
        *(_BYTE *)(a2 + 200) = 4;
        return result;
      }
      if ( (_DWORD)result == 7 )
      {
        *(_BYTE *)(a2 + 200) = 2;
        return ipa3_get_usb_gsi_stats((_DWORD *)a2);
      }
    }
    goto LABEL_21;
  }
  if ( (int)result > 2 )
  {
    if ( (_DWORD)result == 3 )
    {
      *(_BYTE *)(a2 + 200) = 2;
      return ipa3_get_wdi_gsi_stats((_DWORD *)a2);
    }
    if ( (_DWORD)result == 4 )
    {
      *(_BYTE *)(a2 + 200) = 3;
      return ipa3_get_wdi3_gsi_stats(a2);
    }
    goto LABEL_21;
  }
  if ( (_DWORD)result == 1 )
  {
    *(_BYTE *)(a2 + 200) = 2;
    return ipa3_get_aqc_gsi_stats((_DWORD *)a2);
  }
  if ( (_DWORD)result != 2 )
  {
LABEL_21:
    v2 = result;
    result = printk(&unk_3B07B5, "ipa3_get_gsi_stats");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = v2;
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d unsupported HW feature %d\n", "ipa3_get_gsi_stats", 13907, v2);
        v3 = ipa3_ctx;
        v4 = v2;
      }
      result = *(_QWORD *)(v3 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d unsupported HW feature %d\n", "ipa3_get_gsi_stats", 13907, v4);
    }
  }
  return result;
}
