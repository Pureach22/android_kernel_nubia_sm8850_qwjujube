__int64 __fastcall msm_audio_dma_buf_unmap(const void *a1, __int64 a2)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x8
  _QWORD *v4; // x9
  __int64 v5; // x0

  v2 = (_QWORD *)(a2 + 24);
  do
  {
    v2 = (_QWORD *)*v2;
    if ( v2 == (_QWORD *)(a2 + 24) )
      return dev_err(*(_QWORD *)(a2 + 8), "%s: cannot find allocation, dma_buf %pK", "msm_audio_dma_buf_unmap", a1);
  }
  while ( (const void *)*(v2 - 3) != a1 );
  dma_buf_unmap_attachment_unlocked(*(v2 - 2), *(v2 - 1), 0);
  dma_buf_detach(*(v2 - 3), *(v2 - 2));
  dma_buf_put(*(v2 - 3));
  v3 = (_QWORD *)v2[1];
  if ( (_QWORD *)*v3 == v2 && (v4 = (_QWORD *)*v2, *(_QWORD **)(*v2 + 8LL) == v2) )
  {
    v4[1] = v3;
    *v3 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(v2);
  }
  v5 = *(v2 - 4);
  *v2 = 0xDEAD000000000100LL;
  v2[1] = 0xDEAD000000000122LL;
  kfree(v5);
  return kfree(v2 - 5);
}
