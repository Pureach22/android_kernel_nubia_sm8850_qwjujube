__int64 __fastcall p2p_get_frame_info(
        unsigned __int8 *a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w8
  unsigned int v12; // w9
  unsigned int v13; // w9
  int v14; // w8
  __int64 v16; // x20
  int v17; // w0
  unsigned int v18; // w8
  __int64 v20; // x20
  int v21; // w8
  const char *v22; // x4
  int v23; // w8
  __int64 v24; // x8

  *(_QWORD *)a3 = 0xE00000001LL;
  *(_QWORD *)(a3 + 8) = 0x300000011LL;
  if ( a2 > 0x18 )
  {
    v12 = *a1;
    if ( (v12 & 0xC) != 0 )
    {
      qdf_trace_msg(0x4Eu, 2u, "%s: just support mgmt frame", a4, a5, a6, a7, a8, a9, a10, a11, "p2p_get_frame_info");
      return 16;
    }
    v13 = v12 >> 4;
    v11 = 0;
    *(_DWORD *)a3 = 0;
    *(_DWORD *)(a3 + 4) = v13;
    if ( v13 != 13 )
      return v11;
    if ( a2 >= 0x1F )
    {
      v14 = a1[24];
      if ( v14 == 10 )
      {
        if ( a1[25] != 7 )
          goto LABEL_28;
        v18 = 14;
      }
      else
      {
        if ( v14 != 5 )
        {
          if ( v14 == 4 && a1[25] == 9 )
          {
            v16 = a3;
            v17 = qdf_mem_cmp(a1 + 26, &unk_89A401, 4u);
            a3 = v16;
            if ( !v17 )
            {
              v18 = a1[30];
              if ( v18 >= 9 )
                v18 = 17;
              goto LABEL_27;
            }
          }
LABEL_28:
          if ( *(_DWORD *)a3 == 1 )
          {
            v22 = "Not support frame";
          }
          else if ( *(_DWORD *)(a3 + 4) == 14 )
          {
            v22 = "Not support sub frame";
          }
          else
          {
            v23 = *(_DWORD *)(a3 + 12);
            if ( v23 == 1 )
            {
              v22 = "P2P action presence request";
            }
            else if ( v23 == 2 )
            {
              v22 = "P2P action presence response";
            }
            else
            {
              v24 = *(unsigned int *)(a3 + 8);
              if ( (unsigned int)v24 > 0x10 )
                v22 = "Other frame";
              else
                v22 = off_9FDC68[v24];
            }
          }
          qdf_trace_msg(0x4Eu, 8u, "%s: %s", a4, a5, a6, a7, a8, a9, a10, a11, "p2p_get_frame_info", v22);
          return 0;
        }
        if ( a1[25] == 5 )
        {
          v18 = 16;
        }
        else
        {
          if ( a1[25] )
            goto LABEL_28;
          v18 = 15;
        }
      }
LABEL_27:
      *(_DWORD *)(a3 + 8) = v18;
      goto LABEL_28;
    }
    if ( a2 != 30 || a1[24] != 127 || (v20 = a3, (unsigned int)qdf_mem_cmp(a1 + 25, &unk_89A401, 4u)) )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: this is not vendor specific p2p action frame",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "p2p_get_frame_info");
      return 0;
    }
    v21 = a1[29];
    a3 = v20;
    if ( v21 == 2 || v21 == 1 )
      *(_DWORD *)(v20 + 12) = v21;
    goto LABEL_28;
  }
  qdf_trace_msg(0x4Eu, 2u, "%s: invalid p2p mgmt hdr len", a4, a5, a6, a7, a8, a9, a10, a11, "p2p_get_frame_info");
  return 4;
}
