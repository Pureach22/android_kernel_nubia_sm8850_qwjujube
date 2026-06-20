void *__fastcall msm_hdcp_cache_repeater_topology(__int64 a1, const void *a2)
{
  __int64 v2; // x8
  void *v4; // x0

  if ( !a1 || !a2 )
  {
    v4 = &unk_26B171;
    return (void *)printk(v4, "msm_hdcp_cache_repeater_topology");
  }
  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 )
  {
    v4 = &unk_2339E9;
    return (void *)printk(v4, "msm_hdcp_cache_repeater_topology");
  }
  return memcpy((void *)(v2 + 168), a2, 0x290u);
}
