__int64 __fastcall action_oui_send(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int *v10; // x20
  __int64 v12; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  int v22; // w23
  __int64 v23; // x0
  int v24; // w8
  __int64 v25; // x19
  __int64 v26; // x1
  __int64 v27; // x22
  __int64 v28; // x8
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x9
  __int64 v32; // x11
  __int64 v33; // x10
  unsigned int v34; // w20
  __int64 v35; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v36[2]; // [xsp+10h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36[0] = 0;
  if ( a2 >= 0x1C )
    __break(0x5512u);
  v10 = *(int **)(a1 + 8LL * a2 + 23544);
  if ( v10 )
  {
    if ( *(_BYTE *)(a1 + 8) )
    {
      v12 = a1 + 20480;
      qdf_mutex_acquire((__int64)(v10 + 8));
      if ( (unsigned int)(*(_DWORD *)(v12 + 3052) - *(_DWORD *)(v12 + 3056)) <= *(_DWORD *)(v12 + 3060) )
      {
        v22 = v10[6];
        v23 = _qdf_mem_malloc((unsigned int)(68 * v22 + 16), "action_oui_send", 783);
        if ( v23 )
        {
          v24 = *v10;
          *(_DWORD *)(v23 + 8) = v22;
          v25 = v23;
          *(_DWORD *)v23 = v24;
          *(_DWORD *)(v23 + 12) = *(_DWORD *)(v12 + 3060);
          *(_BYTE *)(v23 + 4) = *(_BYTE *)(v12 + 3296);
          qdf_list_peek_front((_QWORD *)v10 + 1, v36);
          v26 = v36[0];
          if ( v36[0] )
          {
            v27 = v25 + 16;
            do
            {
              *(_QWORD *)v27 = *(_QWORD *)(v26 + 16);
              v28 = *(_QWORD *)(v26 + 48);
              v29 = *(_QWORD *)(v26 + 24);
              v30 = *(_QWORD *)(v26 + 32);
              *(_QWORD *)(v27 + 24) = *(_QWORD *)(v26 + 40);
              *(_QWORD *)(v27 + 32) = v28;
              *(_QWORD *)(v27 + 8) = v29;
              *(_QWORD *)(v27 + 16) = v30;
              v32 = *(_QWORD *)(v26 + 64);
              v31 = *(_QWORD *)(v26 + 72);
              v33 = *(_QWORD *)(v26 + 56);
              *(_DWORD *)(v27 + 64) = *(_DWORD *)(v26 + 80);
              *(_QWORD *)(v27 + 48) = v32;
              *(_QWORD *)(v27 + 56) = v31;
              *(_QWORD *)(v27 + 40) = v33;
              if ( (unsigned int)qdf_list_peek_next((_QWORD *)v10 + 1, (_QWORD *)v26, &v35) )
                break;
              v26 = v35;
              v27 += 68;
              v35 = 0;
              v36[0] = v26;
            }
            while ( v26 );
          }
          qdf_mutex_release((__int64)(v10 + 8));
          v34 = tgt_action_oui_send(*(_QWORD *)a1, v25);
          _qdf_mem_free(v25);
          result = v34;
        }
        else
        {
          qdf_mutex_release((__int64)(v10 + 8));
          result = 2;
        }
      }
      else
      {
        qdf_trace_msg(
          0x63u,
          2u,
          "%s: total configured extensions: %d exceeds max_extensions: %d, do not update",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "action_oui_send");
        qdf_mutex_release((__int64)(v10 + 8));
        result = 16;
      }
    }
    else
    {
      qdf_trace_msg(0x63u, 8u, "%s: action_oui is not enable", a3, a4, a5, a6, a7, a8, a9, a10, "action_oui_send");
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
