__int64 __fastcall cfg80211_vendor_cmd_get_sender(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 - 696);
    if ( v3 )
    {
      return *(unsigned int *)(v3 + 4);
    }
    else
    {
      __break(0x800u);
      return 0;
    }
  }
  else
  {
    __break(0x800u);
    __arm_mte_increment_tag((void *)(a3 + 784), 6u);
    return nl80211_notify_wiphy(0, a2);
  }
}
