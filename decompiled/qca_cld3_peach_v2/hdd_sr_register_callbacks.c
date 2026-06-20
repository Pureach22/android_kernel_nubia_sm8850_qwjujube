__int64 __fastcall hdd_sr_register_callbacks(_QWORD *a1)
{
  return ucfg_spatial_reuse_register_cb(*a1, hdd_sr_osif_events);
}
