__int64 __fastcall kgsl_destroy_ion(__int64 result)
{
  _QWORD *v1; // x20
  __int64 v2; // x19
  _QWORD *v3; // x21
  __int64 v4; // x0
  __int64 v5; // x22
  _QWORD *v6; // x8
  _QWORD *v7; // x0
  __int64 v8; // x9
  unsigned __int64 v9; // x9
  _QWORD *v10; // x8
  _QWORD *v11; // x0
  __int64 v12; // x10
  __int64 v13; // x8
  unsigned __int64 v20; // x3

  v1 = *(_QWORD **)(result + 208);
  if ( (*(_DWORD *)(result + 48) & 8) == 0 )
  {
    v2 = result;
    if ( v1 )
    {
      v3 = (_QWORD *)v1[4];
      v4 = v1[1];
      if ( v3 )
      {
        v5 = *(_QWORD *)(*(_QWORD *)(v4 + 8) + 152LL);
        raw_spin_lock(&kgsl_dmabuf_lock);
        v6 = (_QWORD *)v1[6];
        v7 = v1 + 5;
        if ( (_QWORD *)*v6 == v1 + 5 && (v8 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
        {
          *(_QWORD *)(v8 + 8) = v6;
          *v6 = v8;
        }
        else
        {
          _list_del_entry_valid_or_report(v7);
        }
        v9 = 0xDEAD000000000100LL;
        v1[5] = 0xDEAD000000000100LL;
        v1[6] = 0xDEAD000000000122LL;
        if ( (_QWORD *)v3[3] == v3 + 3 )
        {
          v10 = (_QWORD *)v3[2];
          v11 = v3 + 1;
          if ( (_QWORD *)*v10 == v3 + 1 && (v12 = *v11, *(_QWORD **)(*v11 + 8LL) == v11) )
          {
            *(_QWORD *)(v12 + 8) = v10;
            *v10 = v12;
          }
          else
          {
            _list_del_entry_valid_or_report(v11);
          }
          v3[1] = v9;
          v3[2] = v9 + 34;
          kfree(v3);
          v13 = -*(_QWORD *)(*v1 + 48LL);
          _X9 = (unsigned __int64 *)(v5 + 11136);
          __asm { PRFM            #0x11, [X9] }
          do
            v20 = __ldxr(_X9);
          while ( __stlxr(v20 + v13, _X9) );
          __dmb(0xBu);
        }
        raw_spin_unlock(&kgsl_dmabuf_lock);
        v4 = v1[1];
      }
      dma_buf_unmap_attachment_unlocked(v4, *(_QWORD *)(v2 + 56), 0);
      dma_buf_detach(v1[2], v1[1]);
      dma_buf_put(v1[2]);
      result = kfree(v1);
    }
    *(_QWORD *)(v2 + 56) = 0;
  }
  return result;
}
