__int64 __fastcall sub_304390(__int64 a1, __int64 a2)
{
  __int64 v2; // x15
  __int128 v3; // q21
  __int128 v4; // q24

  *(_OWORD *)(v2 + 208) = v3;
  *(_OWORD *)(v2 + 224) = v4;
  return wlan_cm_tgt_send_roam_invoke_req(a1, a2);
}
