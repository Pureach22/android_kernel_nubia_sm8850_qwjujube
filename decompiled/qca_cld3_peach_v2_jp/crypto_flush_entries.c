__int64 __fastcall crypto_flush_entries(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w23
  __int64 v12; // x24
  _QWORD *v13; // x9
  __int64 *v14; // x8
  __int64 v15; // x25
  __int64 *v16; // x26
  unsigned int v17; // w8
  unsigned int v18; // w22
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  _QWORD *v27; // x8
  __int64 v28; // x9
  __int64 v29; // x24
  unsigned __int8 *v30; // x23
  unsigned int v37; // w9
  __int64 v38; // [xsp+0h] [xbp-20h]
  __int64 v39; // [xsp+8h] [xbp-18h] BYREF
  __int64 *v40; // [xsp+10h] [xbp-10h]
  __int64 v41; // [xsp+18h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = &v39;
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 14);
  if ( result )
  {
    v2 = result;
    if ( *(_DWORD *)(result + 72) )
    {
      if ( *(_QWORD *)(result + 80) && *(_DWORD *)(result + 64) )
      {
        qdf_mutex_acquire(result);
        v11 = 0;
        do
        {
          v12 = *(_QWORD *)(*(_QWORD *)(v2 + 80) + 16LL * v11);
          if ( v12 )
          {
            do
            {
              v16 = (__int64 *)(v12 + 152);
              v15 = *(_QWORD *)(v12 + 152);
              v17 = (unsigned __int16)(*(_WORD *)v12
                                     ^ *(unsigned __int8 *)(v12 + 9)
                                     ^ *(_WORD *)(v12 + 2)
                                     ^ *(_WORD *)(v12 + 4));
              v18 = ((v17 >> *(_DWORD *)(v2 + 76)) ^ v17) & *(_DWORD *)(v2 + 72);
              qdf_trace_msg(
                0x1Cu,
                4u,
                "%s: crypto remove entry key index %d link id %d",
                v3,
                v4,
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                "crypto_remove_entry",
                v18);
              v19 = *(_QWORD *)(v12 + 16);
              if ( v19 )
              {
                _qdf_mem_free(v19);
                *(_QWORD *)(v12 + 16) = 0;
              }
              v20 = *(_QWORD *)(v12 + 24);
              if ( v20 )
              {
                _qdf_mem_free(v20);
                *(_QWORD *)(v12 + 24) = 0;
              }
              v21 = *(_QWORD *)(v12 + 32);
              if ( v21 )
              {
                _qdf_mem_free(v21);
                *(_QWORD *)(v12 + 32) = 0;
              }
              v22 = *(_QWORD *)(v12 + 40);
              if ( v22 )
              {
                _qdf_mem_free(v22);
                *(_QWORD *)(v12 + 40) = 0;
              }
              v23 = *(_QWORD *)(v12 + 48);
              if ( v23 )
              {
                _qdf_mem_free(v23);
                *(_QWORD *)(v12 + 48) = 0;
              }
              v24 = *(_QWORD *)(v12 + 56);
              if ( v24 )
              {
                _qdf_mem_free(v24);
                *(_QWORD *)(v12 + 56) = 0;
              }
              v25 = *(_QWORD *)(v12 + 64);
              if ( v25 )
              {
                _qdf_mem_free(v25);
                *(_QWORD *)(v12 + 64) = 0;
              }
              v26 = *(_QWORD *)(v12 + 72);
              if ( v26 )
              {
                _qdf_mem_free(v26);
                *(_QWORD *)(v12 + 72) = 0;
              }
              v28 = *(_QWORD *)(v12 + 152);
              v27 = *(_QWORD **)(v12 + 160);
              *(_WORD *)(v12 + 148) = 0;
              *(_BYTE *)(v12 + 150) = 0;
              if ( v28 )
                v13 = (_QWORD *)(v28 + 160);
              else
                v13 = (_QWORD *)(*(_QWORD *)(v2 + 80) + 16LL * v18 + 8);
              *v13 = v27;
              *v27 = *(_QWORD *)(v12 + 152);
              v14 = v40;
              *(_QWORD *)(v12 + 152) = 0;
              *(_QWORD *)(v12 + 160) = v14;
              *v14 = v12;
              v12 = v15;
              v40 = v16;
            }
            while ( v15 );
          }
          ++v11;
        }
        while ( v11 <= *(_DWORD *)(v2 + 72) );
        v29 = v39;
        while ( v29 )
        {
          v30 = (unsigned __int8 *)v29;
          v29 = *(_QWORD *)(v29 + 152);
          LODWORD(v38) = v30[5];
          qdf_trace_msg(
            0x1Cu,
            8u,
            "%s: crypto delete for link_id %d mac_addr %02x:%02x:%02x:**:**:%02x",
            v3,
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            "crypto_free_list",
            v30[9],
            *v30,
            v30[1],
            v30[2],
            v38);
          _qdf_mem_free((__int64)v30);
          if ( *(_DWORD *)(v2 + 64) )
          {
            _X8 = (unsigned int *)(v2 + 64);
            __asm { PRFM            #0x11, [X8] }
            do
              v37 = __ldxr(_X8);
            while ( __stxr(v37 - 1, _X8) );
          }
          else
          {
            qdf_trace_msg(0x1Cu, 8u, "%s: Invalid crypto_key_cnt", v3, v4, v5, v6, v7, v8, v9, v10, "crypto_free_list");
          }
        }
        result = qdf_mutex_release(v2);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
