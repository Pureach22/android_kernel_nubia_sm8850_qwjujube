__int64 __fastcall dlm_remove_lowest_delta_entry(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  result = dlm_try_delete_bssid_in_list(a1, 5, a2);
  if ( (_DWORD)result )
  {
    result = dlm_try_delete_bssid_in_list(a1, 2, a2);
    if ( (_DWORD)result )
    {
      result = dlm_try_delete_bssid_in_list(a1, 0, a2);
      if ( (_DWORD)result )
      {
        result = dlm_try_delete_bssid_in_list(a1, 4, a2);
        if ( (_DWORD)result )
        {
          result = dlm_try_delete_bssid_in_list(a1, 3, a2);
          if ( (_DWORD)result )
          {
            result = dlm_try_delete_bssid_in_list(a1, 1, a2);
            if ( (_DWORD)result )
            {
              qdf_trace_msg(
                0x6Du,
                8u,
                "%s: Failed to remove AP from denylist manager",
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                "dlm_remove_lowest_delta_entry");
              return 16;
            }
          }
        }
      }
    }
  }
  return result;
}
