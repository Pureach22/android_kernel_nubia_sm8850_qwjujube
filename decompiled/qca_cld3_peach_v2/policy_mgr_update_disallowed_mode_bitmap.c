__int64 __fastcall policy_mgr_update_disallowed_mode_bitmap(__int64 a1, __int64 a2, _DWORD *a3, unsigned int a4)
{
  __int64 result; // x0
  __int16 emlsr_mode_disable_req; // w0
  _DWORD *v10; // x2
  int connection_count_with_mlo; // w0

  result = 0;
  if ( a2 && a3 )
  {
    if ( *(_QWORD *)(a2 + 1360)
      && (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) != 0
      && (wlan_mlme_is_aux_emlsr_support(a1) & 1) != 0 )
    {
      emlsr_mode_disable_req = ml_nlink_get_emlsr_mode_disable_req(a1, a2);
      v10 = a3;
      a3[32] = -1;
      a3[34] = -1;
      a3[36] = -1;
      a3[38] = -1;
      if ( (emlsr_mode_disable_req & 0x3FE) == 0 )
      {
        connection_count_with_mlo = policy_mgr_get_connection_count_with_mlo(a1);
        v10 = a3;
        if ( connection_count_with_mlo == 1 )
        {
          ml_nlink_clr_emlsr_mode_disable_req(a1, a2, 1);
          v10 = a3;
        }
      }
      ml_nlink_populate_disallow_modes(a1, a2, v10, a4);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
