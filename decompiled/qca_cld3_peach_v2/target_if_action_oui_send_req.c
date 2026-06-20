__int64 __fastcall target_if_action_oui_send_req(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 2800)) != 0 && (v2 = *(_QWORD *)(v1 + 16)) != 0 )
    return wmi_unified_send_action_oui_cmd(v2);
  else
    return 16;
}
