__int64 __fastcall lim_send_mlo_caps_ie(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v7; // x0
  __int64 v8; // x20

  v7 = _qdf_mem_malloc(0x92Cu, "lim_send_mlo_caps_ie", 8566);
  if ( !v7 )
    return 2;
  v8 = v7;
  populate_dot11f_mlo_ie(a1, a2, v7);
  lim_send_ie(a4, 0xFFu, 1, (const void *)(v8 + 2092), *(unsigned __int16 *)(v8 + 2088) - 2);
  lim_send_ie(a4, 0xFFu, 2, (const void *)(v8 + 2092), *(unsigned __int16 *)(v8 + 2088) - 2);
  _qdf_mem_free(v8);
  return 0;
}
