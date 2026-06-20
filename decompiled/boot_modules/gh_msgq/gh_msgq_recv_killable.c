__int64 __fastcall gh_msgq_recv_killable(__int64 a1, __int64 a2, unsigned __int64 a3, _QWORD *a4, __int64 a5)
{
  return gh_msgq_recv_state(a1, a2, a3, a4, a5, 0x102u);
}
