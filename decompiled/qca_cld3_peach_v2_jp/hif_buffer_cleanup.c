__int64 __fastcall hif_buffer_cleanup(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x22
  __int64 v3; // x24
  unsigned __int64 v4; // x28
  __int64 v5; // x20
  int v6; // w9
  __int64 v7; // x21
  __int64 v8; // x21
  __int64 v9; // x20
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  int v12; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-28h] BYREF
  __int64 v14; // [xsp+10h] [xbp-20h] BYREF
  __int64 v15; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v16[2]; // [xsp+20h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 656) )
  {
    v1 = result;
    v2 = 0;
    v3 = result + 27416;
    do
    {
      if ( v2 == 12 )
        __break(0x5512u);
      v4 = v3 + 136 * v2;
      if ( *(_DWORD *)(v4 + 32) )
      {
        v5 = *(_QWORD *)(v4 + 16);
        if ( *(_BYTE *)(v5 + 26440) == 1 )
        {
          if ( *(_QWORD *)(v5 + 576) )
          {
            v16[0] = 0;
            v6 = *(unsigned __int8 *)(v4 + 8);
            v7 = *(_QWORD *)v4;
            v14 = 0;
            v15 = 0;
            if ( *(_DWORD *)(v5 + 26432) == v6 )
            {
              result = hif_prealloc_put_multi_pages(v5, 15, v5 + 26392, 0);
            }
            else
            {
              while ( 1 )
              {
                result = ce_revoke_recv_next(v7, &v14, v16, &v15);
                if ( (_DWORD)result )
                  break;
                if ( v16[0] )
                {
                  _qdf_nbuf_unmap_single(*(_QWORD *)(v5 + 576), v16[0], 2);
                  if ( v16[0] )
                    _qdf_nbuf_free(v16[0]);
                }
              }
            }
          }
        }
      }
      if ( *(_DWORD *)(v4 + 32) )
      {
        v8 = *(_QWORD *)(v4 + 16);
        if ( *(_BYTE *)(v8 + 26440) == 1 )
        {
          v9 = *(_QWORD *)v4;
          v16[0] = 0;
          v14 = 0;
          v15 = 0;
          v13 = 0;
          v12 = 0;
          while ( 1 )
          {
            result = ce_cancel_send_next(v9, &v15, v16, &v14, (char *)&v13 + 4, &v13, &v12);
            if ( (_DWORD)result )
              break;
            if ( v16[0] != 3469655791LL )
            {
              if ( (_DWORD)v13 == *(_DWORD *)(v8 + 724) )
                break;
              v10 = *(void (__fastcall **)(_QWORD))(v4 + 96);
              if ( v10 )
              {
                v11 = *(_QWORD *)(v4 + 88);
                if ( *((_DWORD *)v10 - 1) != 1016259708 )
                  __break(0x8228u);
                v10(v11);
              }
            }
          }
        }
      }
      ++v2;
    }
    while ( v2 < *(unsigned int *)(v1 + 656) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
