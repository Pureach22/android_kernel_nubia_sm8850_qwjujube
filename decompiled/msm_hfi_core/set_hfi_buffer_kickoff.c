__int64 __fastcall set_hfi_buffer_kickoff(__int64 a1)
{
  if ( (virtqueue_kick(*(_QWORD *)(a1 + 1080)) & 1) != 0 )
    return 0;
  else
    return 4294967274LL;
}
