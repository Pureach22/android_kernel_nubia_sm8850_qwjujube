__int64 __fastcall rmnet_frag_flow_command(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  unsigned __int8 *v6; // x0
  int v7; // w8
  __int64 result; // x0
  int v9; // w21
  unsigned __int8 *v10; // x22
  unsigned int *v11; // x0
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x11
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x8
  unsigned __int8 *v20; // x22
  int v21; // w21
  unsigned int *v22; // x0
  __int64 v23; // x9
  int v24; // w21
  unsigned __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // [xsp+0h] [xbp-20h] BYREF
  __int64 v28; // [xsp+8h] [xbp-18h] BYREF
  __int64 v29; // [xsp+10h] [xbp-10h]
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v6 = (unsigned __int8 *)rmnet_frag_header_ptr(a1, 4u, 8u, (__int64)&v27);
  if ( v6 )
  {
    v7 = *v6;
    if ( *(_DWORD *)(a1 + 56) != 55834 || (unsigned int)(v7 - 7) >= 2 )
    {
      switch ( v7 )
      {
        case 35:
          if ( a3 >= 0x18u )
          {
            v24 = *(_DWORD *)(a2 + 8);
            v28 = 0;
            v29 = 0;
            v25 = rmnet_frag_header_ptr(a1, 0xCu, 0x10u, (__int64)&v28);
            if ( v25 )
            {
              ++*(_QWORD *)(a2 + 2712);
              if ( (v24 & 0x20000000) != 0 )
              {
                v26 = rmnet_map_pb_ind_notify(a2, v25);
                rmnet_mem_pb_ind(v26);
              }
            }
          }
          break;
        case 8:
          if ( a3 >= 0xCu )
          {
            v20 = v6;
            v21 = *(_DWORD *)(a2 + 8);
            LODWORD(v28) = 0;
            v22 = (unsigned int *)rmnet_frag_header_ptr(a1, 0xCu, 4u, (__int64)&v28);
            if ( v22 )
            {
              v23 = *(_QWORD *)(a2 + 2584);
              *(_QWORD *)(a2 + 2576) = *v22;
              *(_QWORD *)(a2 + 2584) = v23 + 1;
              if ( (v21 & 0x20000000) != 0 )
                rmnet_map_dl_trl_notify_v2(a2, v22, v20);
            }
          }
          break;
        case 7:
          if ( a3 >= 0x18u )
          {
            v9 = *(_DWORD *)(a2 + 8);
            v10 = v6;
            v28 = 0;
            v29 = 0;
            v11 = (unsigned int *)rmnet_frag_header_ptr(a1, 0xCu, 0x10u, (__int64)&v28);
            if ( v11 )
            {
              v12 = *(_QWORD *)(a2 + 2560);
              v13 = *(_QWORD *)(a2 + 2568);
              *(_QWORD *)(a2 + 2504) = *((_WORD *)v10 + 1) & 0x7FFF;
              *(_QWORD *)(a2 + 2496) = ((unsigned __int64)v10[1] >> 2) & 0x1F;
              *(_QWORD *)(a2 + 2512) = *((unsigned int *)v10 + 1);
              *(_QWORD *)(a2 + 2520) = *v11;
              v14 = v11[1];
              *(_QWORD *)(a2 + 2528) = v14;
              v15 = v12 + v14;
              v16 = v11[2];
              *(_QWORD *)(a2 + 2536) = v16;
              v17 = v13 + v16;
              v18 = v11[3];
              *(_QWORD *)(a2 + 2560) = v15;
              v19 = *(_QWORD *)(a2 + 2552);
              *(_QWORD *)(a2 + 2568) = v17;
              *(_QWORD *)(a2 + 2544) = v18;
              *(_QWORD *)(a2 + 2552) = v19 + 1;
              if ( (v9 & 0x20000000) != 0 )
                rmnet_map_dl_hdr_notify_v2(a2, v11, v10);
            }
          }
          break;
        default:
          result = 1;
          goto LABEL_6;
      }
    }
    result = 0;
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
