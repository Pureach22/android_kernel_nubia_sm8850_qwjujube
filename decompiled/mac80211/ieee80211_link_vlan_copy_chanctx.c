__int64 __fastcall ieee80211_link_vlan_copy_chanctx(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9

  if ( *(_DWORD *)(*(_QWORD *)result + 4720LL) == 4 && (v1 = *(_QWORD *)(*(_QWORD *)result + 2032LL)) != 0 )
  {
    v2 = *(unsigned int *)(result + 8);
    if ( (unsigned int)v2 >= 0xF )
    {
      __break(0x5512u);
      return ieee80211_iter_chan_contexts_atomic();
    }
    else
    {
      atomic_store(
        *(_QWORD *)(*(_QWORD *)(v1 + 8 * v2 + 3416) + 832LL),
        (unsigned __int64 *)(*(_QWORD *)(result + 944) + 832LL));
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
