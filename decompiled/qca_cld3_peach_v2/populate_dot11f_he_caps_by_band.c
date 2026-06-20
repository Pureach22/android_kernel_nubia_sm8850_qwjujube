__int64 __fastcall populate_dot11f_he_caps_by_band(__int64 a1, char a2, __int64 a3, __int64 a4)
{
  if ( (a2 & 1) != 0 )
  {
    qdf_mem_copy((void *)a3, (const void *)(a1 + 21788), 0x3Cu);
    if ( a4 )
    {
      *(_QWORD *)(a3 + 1) = *(_QWORD *)(a3 + 1) & 0xFFFBFFFFFFFFFFFFLL
                          | ((lim_get_sta_cb_mode_for_24ghz(a1, *(unsigned __int8 *)(a4 + 10)) & 1) << 50);
LABEL_5:
      populate_dot11f_twt_he_cap(a1, a4, a3);
    }
  }
  else
  {
    qdf_mem_copy((void *)a3, (const void *)(a1 + 21848), 0x3Cu);
    if ( a4 )
      goto LABEL_5;
  }
  return 0;
}
