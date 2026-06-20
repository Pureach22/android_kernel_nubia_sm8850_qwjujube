__int64 __fastcall sps_bam_pipe_enable(__int64 a1, unsigned int a2)
{
  __int64 v2; // x19

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    return sps_bam_pipe_disable();
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 8LL * a2 + 256);
    bam_pipe_enable(a1 + 216, a2);
    *(_DWORD *)(v2 + 184) |= 8u;
    return 0;
  }
}
