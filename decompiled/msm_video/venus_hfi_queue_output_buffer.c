__int64 __fastcall venus_hfi_queue_output_buffer(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v6; // x19
  __int64 v7; // x4
  _QWORD *v8; // x8
  _QWORD *v9; // x9
  void *v10; // x0
  unsigned int hfi_buffer; // w23
  int v12; // w3
  __int64 v13; // x0
  unsigned int v14; // w1
  int v15; // w2
  unsigned int *v16; // x23
  unsigned int v17; // w24
  int hfi_port_from_buffer_type; // w0
  int v19; // w6
  unsigned int *v20; // x23
  unsigned int v21; // w24
  int v22; // w0
  int v23; // w6
  int v24; // w0
  int v25; // w6
  int v26; // w22
  unsigned int *v27; // x0
  unsigned int v28; // w1
  bool v29; // zf
  int v30; // w4
  int v31; // w6
  unsigned int *v32; // x0
  unsigned int v33; // w1
  int v34; // w6
  unsigned int *v35; // x0
  unsigned int v36; // w1
  int v37; // w0
  int v38; // w6
  int v39; // w22
  unsigned int *v40; // x0
  unsigned int v41; // w1
  int v42; // w4
  int v43; // w6
  unsigned int *v44; // x0
  unsigned int v45; // w1
  int v46; // w6
  unsigned int *v47; // x0
  unsigned int v48; // w1
  __int64 v50; // [xsp+10h] [xbp-90h] BYREF
  _QWORD v51[8]; // [xsp+18h] [xbp-88h] BYREF
  _QWORD v52[4]; // [xsp+58h] [xbp-48h] BYREF
  __int64 v53; // [xsp+78h] [xbp-28h]
  __int64 v54; // [xsp+80h] [xbp-20h]
  __int64 v55; // [xsp+88h] [xbp-18h]
  __int64 v56; // [xsp+90h] [xbp-10h]
  __int64 v57; // [xsp+98h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 320);
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  memset(v52, 0, sizeof(v52));
  memset(v51, 0, sizeof(v51));
  v50 = 0;
  core_lock(v6);
  if ( !*(_QWORD *)(a1 + 368) )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_40;
    v10 = &unk_8DDBA;
    goto LABEL_13;
  }
  if ( (mutex_is_locked(v6 + 3856) & 1) == 0 )
  {
    __break(0x800u);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_output_buffer");
    goto LABEL_40;
  }
  v8 = (_QWORD *)(v6 + 3528);
  v9 = (_QWORD *)(v6 + 3528);
  do
    v9 = (_QWORD *)*v9;
  while ( v9 != (_QWORD *)a1 && v9 != v8 );
  if ( a1 && v9 == v8 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
    {
LABEL_40:
      hfi_buffer = -22;
      goto LABEL_41;
    }
    v10 = &unk_89648;
LABEL_13:
    printk(v10, "err ", a1 + 340, "venus_hfi_queue_output_buffer", v7);
    goto LABEL_40;
  }
  if ( v9 == v8 )
    goto LABEL_40;
  hfi_buffer = get_hfi_buffer(a1, (__int64)a2, (__int64)v52);
  if ( !hfi_buffer )
  {
    v12 = *(_DWORD *)(v6 + 6600);
    v13 = *(_QWORD *)(a1 + 368);
    v14 = *(_DWORD *)(a1 + 376);
    v15 = *(_DWORD *)(a1 + 332);
    *(_DWORD *)(v6 + 6600) = v12 + 1;
    hfi_buffer = hfi_create_header(v13, v14, v15, v12);
    if ( !hfi_buffer )
    {
      v16 = *(unsigned int **)(a1 + 368);
      v17 = *(_DWORD *)(a1 + 376);
      hfi_port_from_buffer_type = get_hfi_port_from_buffer_type(a1, a2[6]);
      v19 = *(_DWORD *)(v6 + 6604);
      *(_DWORD *)(v6 + 6604) = v19 + 1;
      hfi_buffer = hfi_create_packet(v16, v17, 16777225, 1, 5, hfi_port_from_buffer_type, v19, v52, 0x40u);
      if ( !hfi_buffer )
      {
        if ( !a3
          || (hfi_buffer = get_hfi_buffer(a1, a3, (__int64)v51)) == 0
          && (v20 = *(unsigned int **)(a1 + 368),
              v21 = *(_DWORD *)(a1 + 376),
              v22 = get_hfi_port_from_buffer_type(a1, *(_DWORD *)(a3 + 24)),
              v23 = *(_DWORD *)(v6 + 6604),
              *(_DWORD *)(v6 + 6604) = v23 + 1,
              (hfi_buffer = hfi_create_packet(v20, v21, 16777225, 1, 5, v22, v23, v51, 0x40u)) == 0) )
        {
          if ( !*(_QWORD *)(a1 + 14600) )
            goto LABEL_44;
          v24 = get_hfi_port_from_buffer_type(a1, a2[6]);
          v25 = *(_DWORD *)(v6 + 6604);
          v26 = v24;
          v27 = *(unsigned int **)(a1 + 368);
          v28 = *(_DWORD *)(a1 + 376);
          v29 = a2[31] == 1;
          *(_DWORD *)(v6 + 6604) = v25 + 1;
          v30 = v29 ? 3 : 14;
          hfi_buffer = hfi_create_packet(v27, v28, 50332043, 0, v30, v26, v25, a2 + 34, 8 * a2[31]);
          if ( !hfi_buffer )
          {
            v31 = *(_DWORD *)(v6 + 6604);
            v32 = *(unsigned int **)(a1 + 368);
            v33 = *(_DWORD *)(a1 + 376);
            LODWORD(v50) = *(_QWORD *)(a1 + 14768);
            *(_DWORD *)(v6 + 6604) = v31 + 1;
            hfi_buffer = hfi_create_packet(v32, v33, 50332061, 0, 9, v26, v31, &v50, 4u);
            if ( !hfi_buffer )
            {
              v34 = *(_DWORD *)(v6 + 6604);
              v35 = *(unsigned int **)(a1 + 368);
              v36 = *(_DWORD *)(a1 + 376);
              HIDWORD(v50) = 2;
              *(_DWORD *)(v6 + 6604) = v34 + 1;
              hfi_buffer = hfi_create_packet(v35, v36, 50332062, 0, 9, v26, v34, (char *)&v50 + 4, 4u);
              if ( !hfi_buffer )
              {
LABEL_44:
                if ( (*(_BYTE *)(a1 + 5544) & 0x80) == 0 || (~*(_DWORD *)(a1 + 5528) & 9LL) != 0 )
                  goto LABEL_36;
                v37 = get_hfi_port_from_buffer_type(a1, a2[6]);
                v38 = *(_DWORD *)(v6 + 6604);
                v39 = v37;
                v40 = *(unsigned int **)(a1 + 368);
                v41 = *(_DWORD *)(a1 + 376);
                v29 = a2[32] == 1;
                *(_DWORD *)(v6 + 6604) = v38 + 1;
                v42 = v29 ? 3 : 14;
                hfi_buffer = hfi_create_packet(v40, v41, 50332043, 0, v42, v39, v38, a2 + 54, 8 * a2[32]);
                if ( !hfi_buffer )
                {
                  v43 = *(_DWORD *)(v6 + 6604);
                  v44 = *(unsigned int **)(a1 + 368);
                  v45 = *(_DWORD *)(a1 + 376);
                  LODWORD(v50) = *(_QWORD *)(a1 + 14936);
                  *(_DWORD *)(v6 + 6604) = v43 + 1;
                  hfi_buffer = hfi_create_packet(v44, v45, 50332061, 0, 9, v39, v43, &v50, 4u);
                  if ( !hfi_buffer )
                  {
                    v46 = *(_DWORD *)(v6 + 6604);
                    v47 = *(unsigned int **)(a1 + 368);
                    v48 = *(_DWORD *)(a1 + 376);
                    HIDWORD(v50) = 1;
                    *(_DWORD *)(v6 + 6604) = v46 + 1;
                    hfi_buffer = hfi_create_packet(v47, v48, 50332062, 0, 9, v39, v46, (char *)&v50 + 4, 4u);
                    if ( !hfi_buffer )
                    {
LABEL_36:
                      hfi_buffer = _cmdq_write(v6, *(_QWORD *)(a1 + 368));
                      if ( !hfi_buffer )
                        msm_vidc_add_buffer_stats(a1, a2, v53);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_41:
  core_unlock(v6);
  _ReadStatusReg(SP_EL0);
  return hfi_buffer;
}
