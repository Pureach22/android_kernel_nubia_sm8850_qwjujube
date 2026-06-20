__int64 __fastcall rmnet_shs_map_flush_queue(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 v3; // x0

  if ( qword_19468 < 1 )
    return 0;
  if ( HIBYTE(word_19492) == 2 )
  {
    HIBYTE(word_19492) = 0;
    return 0;
  }
  if ( HIBYTE(word_19492) == 1 )
  {
    queue_work_on(32, system_wq, &shs_rx_work);
    return 0;
  }
  if ( HIBYTE(word_19492) )
    return 0;
  HIBYTE(word_19492) = 1;
  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 48) + 48LL);
  if ( *((_DWORD *)v2 - 1) != -432005955 )
    __break(0x8228u);
  v3 = v2();
  hrtimer_forward(a1, v3, 2000000);
  return 1;
}
