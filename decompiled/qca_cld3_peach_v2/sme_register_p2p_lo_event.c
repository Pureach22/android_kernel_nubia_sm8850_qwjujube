__int64 __fastcall sme_register_p2p_lo_event(__int64 a1, __int64 a2, __int64 a3)
{
  qdf_mutex_acquire(a1 + 12848);
  *(_QWORD *)(a1 + 14368) = a3;
  *(_QWORD *)(a1 + 14376) = a2;
  return qdf_mutex_release(a1 + 12848);
}
