__int64 __fastcall cld80211_oem_send_reply(_DWORD *a1, __int64 a2, _WORD *a3, unsigned int a4)
{
  __int64 result; // x0
  int v9; // w8
  __int64 v10; // x0
  __int64 v11; // x3

  result = cld80211_get_genl_family();
  *a3 = a1[54] + a1[52] - (_WORD)a3;
  *(_DWORD *)(a2 - 20) = a1[54] + a1[52] - (a2 - 20);
  if ( *(unsigned __int8 *)(result + 32) <= 6u )
  {
    __break(0x800u);
  }
  else
  {
    v9 = *(_DWORD *)(result + 148);
    v10 = cfg80211_ch_switch_notify;
    v11 = (unsigned int)(v9 + 6);
    a1[14] = v11;
    return netlink_broadcast_filtered(v10, a1, 0, v11, a4, 0, 0);
  }
  return result;
}
