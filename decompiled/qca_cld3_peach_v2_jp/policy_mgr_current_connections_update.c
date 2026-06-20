__int64 __fastcall policy_mgr_current_connections_update(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int actions; // w0
  __int64 v28; // x4
  unsigned int v29; // w22
  __int64 v30; // x20
  unsigned int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, unsigned int *))policy_mgr_get_next_action)(
               a1,
               a2,
               a3,
               a4,
               &v31);
    if ( !(_DWORD)result )
    {
      if ( v31 )
      {
        actions = policy_mgr_next_actions(a1, a2);
        v28 = v31;
        v29 = actions;
      }
      else
      {
        v28 = 0;
        v29 = 11;
      }
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: next_action %d reason=%d session_id=%d request_id %x",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "policy_mgr_current_connections_update",
        v28,
        a4,
        a2,
        a5);
      result = v29;
    }
  }
  else
  {
    v30 = jiffies;
    if ( policy_mgr_current_connections_update___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: driver isn't dbs capable, no further action needed",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "policy_mgr_current_connections_update");
      policy_mgr_current_connections_update___last_ticks = v30;
    }
    result = 11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
