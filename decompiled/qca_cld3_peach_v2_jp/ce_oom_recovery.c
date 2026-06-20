__int64 __fastcall ce_oom_recovery(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  unsigned int v9; // w10

  v2 = *(_DWORD *)(result + 8);
  if ( v2 >= 0xD )
  {
    __break(0x5512u);
  }
  else
  {
    v1 = *(_QWORD *)result;
    result = hif_post_recv_buffers_for_pipe(*(_QWORD *)result + 136LL * v2 + 27416);
  }
  _X8 = (unsigned int *)(v1 + 680);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 - 1, _X8) );
  return result;
}
