__int64 __fastcall handle_output_tx_fence(__int64 a1, _DWORD *a2)
{
  int v2; // w8
  unsigned int *v5; // x26
  _BOOL4 v6; // w21
  int v7; // w8
  int v8; // w9
  __int64 v9; // x27
  __int64 v10; // x28
  __int64 v11; // x22
  unsigned int v12; // w8
  __int64 v13; // x24
  _QWORD *fence_from_id; // x0
  unsigned __int64 v15; // x24
  __int64 v16; // x25
  __int64 v17; // x0
  const char *v18; // x1
  __int64 v19; // x8
  __int64 (__fastcall *v20)(__int64, __int64, _BOOL4); // x8
  unsigned int v21; // w0
  _DWORD *v22; // x8
  __int64 v23; // x4
  unsigned int v24; // w5
  unsigned int v26; // w20

  v2 = *(_DWORD *)(a1 + 14936);
  v5 = (unsigned int *)(a1 + 38368);
  if ( v2 == 1 )
    v6 = a2[12] == 0;
  else
    v6 = v2 == 2 && *(_DWORD *)(a1 + 3580) != 0;
  v7 = *(_DWORD *)(a1 + 3672);
  v8 = a2[31];
  v9 = (unsigned int)(v7 - v8);
  if ( v7 - v8 <= 0 )
  {
    v23 = *v5;
LABEL_24:
    v24 = a2[32];
    if ( (unsigned int)v23 >= v24 )
    {
      *v5 = v23 - v24;
      return 0;
    }
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8AEB6, "err ", a1 + 340, "handle_output_tx_fence", v23);
    }
  }
  else
  {
    v10 = *(_QWORD *)(a1 + 320);
    v11 = 0;
    while ( 1 )
    {
      v12 = v11 + a2[31];
      if ( v12 >= 0xA )
      {
LABEL_38:
        __break(0x5512u);
        JUMPOUT(0x7F3F0);
      }
      v13 = *(_QWORD *)(a1 + 3592 + 8LL * v12);
      fence_from_id = msm_vidc_get_fence_from_id(a1, (_QWORD *)(a1 + 38352), v13);
      if ( !fence_from_id )
        break;
      v15 = fence_from_id[21];
      v16 = (__int64)fence_from_id;
      if ( v6 )
      {
        v17 = 1;
        v18 = "err ";
      }
      else
      {
        if ( v15 <= *((_QWORD *)v5 + 1) )
        {
          if ( a1 && (msm_vidc_debug & 1) != 0 )
            printk(&unk_86E2E, "err ", a1 + 340, "handle_output_tx_fence", v15);
          goto LABEL_35;
        }
        v17 = 2;
        v18 = "high";
      }
      print_fence_buffer(v17, (__int64)v18, (__int64)"destroy", a1, (__int64)a2, v16);
      if ( v10 )
      {
        v19 = *(_QWORD *)(v10 + 6584);
        if ( v19 )
        {
          v20 = *(__int64 (__fastcall **)(__int64, __int64, _BOOL4))(v19 + 48);
          if ( v20 )
          {
            if ( *((_DWORD *)v20 - 1) != -1185588215 )
              __break(0x8228u);
            v21 = v20(a1, v16, v6);
            if ( v21 )
            {
              v26 = v21;
              goto LABEL_36;
            }
          }
        }
      }
      if ( v11 == 10 )
        goto LABEL_38;
      v22 = &a2[2 * v11++];
      *((_QWORD *)v22 + 27) = 0;
      LODWORD(v22) = *v5;
      *((_QWORD *)v5 + 1) = v15;
      v23 = (unsigned int)((_DWORD)v22 + 1);
      *v5 = v23;
      if ( v9 == v11 )
        goto LABEL_24;
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8E723, "err ", a1 + 340, "handle_output_tx_fence", v13);
  }
LABEL_35:
  v26 = -22;
LABEL_36:
  msm_vidc_change_state(a1, 5u, (__int64)"handle_output_tx_fence");
  return v26;
}
