__int64 __fastcall gsi_info_show(__int64 a1, __int64 a2)
{
  __int64 v2; // x26
  __int64 v4; // x0
  const char *v5; // x20
  unsigned int v6; // w21
  __int64 v7; // x21
  __int64 v8; // x22
  __int64 v9; // x22
  __int64 v10; // x22
  __int64 v11; // x22
  __int64 v12; // x22
  __int64 v13; // x22
  __int64 v14; // x23
  __int64 v15; // x23
  __int64 v16; // x23
  __int64 v17; // x23
  __int64 v18; // x23
  __int64 v19; // x28
  __int64 v20; // x28
  __int64 v21; // x28
  __int64 v22; // x28
  __int64 v23; // x28
  __int64 v24; // x28
  __int64 v25; // x28
  __int64 v26; // x28
  __int64 v27; // x28
  __int64 v28; // x24
  __int64 v29; // x24
  __int64 v30; // x24
  __int64 v31; // x24
  __int64 v32; // x24
  __int64 v33; // x24
  __int64 v34; // x24
  __int64 v35; // x24
  __int64 v36; // x23
  __int64 v37; // x23
  __int64 v38; // x23
  __int64 v39; // x23
  __int64 v40; // x21
  __int64 v41; // x23
  __int64 v42; // x22
  int v43; // w0
  __int64 v44; // x22
  __int64 v45; // x22
  unsigned int v46; // w8
  __int64 v47; // x1
  int v48; // w19

  v2 = *(_QWORD *)(a1 + 176);
  v4 = _kmalloc_cache_noprof(ida_alloc_range, 3520, 4096);
  v5 = (const char *)v4;
  if ( !v4 )
    return -12;
  if ( v2 && *(_DWORD *)(v2 + 272) )
  {
    v6 = scnprintf(v4, 4096, "Info: Prot_id:%d\n", *(_DWORD *)(v2 + 224));
    v7 = (unsigned int)scnprintf(&v5[v6], 4096LL - v6, "%55s\n", "==================================================")
       + v6;
    v8 = (unsigned int)v7
       + (unsigned int)scnprintf(&v5[v7], 4096 - v7, "%25s %10s\n", "Ctrl Name: ", (const char *)(v2 + 1056));
    v9 = (unsigned int)scnprintf(&v5[v8], 4096 - v8, "%25s %10u\n", "Ctrl Online: ", *(_DWORD *)(v2 + 1228))
       + (unsigned int)v8;
    v10 = (unsigned int)scnprintf(&v5[v9], 4096 - v9, "%25s %10u\n", "Ctrl Open: ", *(unsigned __int8 *)(v2 + 1232))
        + (unsigned int)v9;
    v11 = (unsigned int)scnprintf(&v5[v10], 4096 - v10, "%25s %10u\n", "Ctrl Host to Modem: ", *(_DWORD *)(v2 + 1316))
        + (unsigned int)v10;
    v12 = (unsigned int)scnprintf(&v5[v11], 4096 - v11, "%25s %10u\n", "Ctrl Modem to Host: ", *(_DWORD *)(v2 + 1328))
        + (unsigned int)v11;
    v13 = (unsigned int)scnprintf(&v5[v12], 4096 - v12, "%25s %10u\n", "Ctrl Cpd to Modem: ", *(_DWORD *)(v2 + 1320))
        + (unsigned int)v12;
    v42 = (unsigned int)scnprintf(&v5[v13], 4096 - v13, "%25s %10u\n", "Ctrl Cpd From Modem: ", *(_DWORD *)(v2 + 1324))
        + (unsigned int)v13;
    v14 = (unsigned int)scnprintf(&v5[v42], 4096 - v42, "%25s %10u\n", "Ctrl Pkt Drops: ", *(_DWORD *)(v2 + 1332))
        + (unsigned int)v42;
    v15 = (unsigned int)v14 + (unsigned int)scnprintf(&v5[v14], 4096 - v14, "%25s\n", "==============");
    v16 = (unsigned int)scnprintf(&v5[v15], 4096 - v15, "%25s %10u\n", "Protocol ID: ", *(_DWORD *)(v2 + 224))
        + (unsigned int)v15;
    v17 = (unsigned int)scnprintf(&v5[v16], 4096 - v16, "%25s %10u\n", "SM State: ", *(_DWORD *)(v2 + 688))
        + (unsigned int)v16;
    v18 = (unsigned int)scnprintf(&v5[v17], 4096 - v17, "%25s %10u\n", "IN XferRscIndex: ", *(_DWORD *)(v2 + 540))
        + (unsigned int)v17;
    v19 = (unsigned int)scnprintf(&v5[v18], 4096 - v18, "%25s %10d\n", "IN Chnl Hdl: ", *(_DWORD *)(v2 + 532))
        + (unsigned int)v18;
    v20 = (unsigned int)scnprintf(&v5[v19], 4096 - v19, "%25s %10x\n", "IN Chnl Dbl Addr: ", *(_DWORD *)(v2 + 352))
        + (unsigned int)v19;
    v21 = (unsigned int)scnprintf(
                          &v5[v20],
                          4096 - v20,
                          "%25s %10u\n",
                          "IN TRB Ring Len: ",
                          *(unsigned __int16 *)(v2 + 876))
        + (unsigned int)v20;
    v22 = (unsigned int)scnprintf(&v5[v21], 4096 - v21, "%25s %10x\n", "IN TRB Base Addr: ", *(_DWORD *)(v2 + 896))
        + (unsigned int)v21;
    v23 = (unsigned int)scnprintf(&v5[v22], 4096 - v22, "%25s %10x\n", "GEVENTCNTLO IN Addr: ", *(_DWORD *)(v2 + 864))
        + (unsigned int)v22;
    v24 = (unsigned int)scnprintf(&v5[v23], 4096 - v23, "%25s %10x\n", "DEPCMDLO IN Addr: ", *(_DWORD *)(v2 + 884))
        + (unsigned int)v23;
    v25 = (unsigned int)scnprintf(
                          &v5[v24],
                          4096 - v24,
                          "%25s %10x\n",
                          "IN LastTRB Addr Off: ",
                          *(unsigned __int16 *)(v2 + 880))
        + (unsigned int)v24;
    v26 = (unsigned int)scnprintf(
                          &v5[v25],
                          4096 - v25,
                          "%25s %10u\n",
                          "IN Buffer Size: ",
                          *(unsigned __int8 *)(v2 + 882))
        + (unsigned int)v25;
    v27 = (unsigned int)scnprintf(&v5[v26], 4096 - v26, "%25s %10u\n", "IN/DL Aggr Size: ", *(_DWORD *)(v2 + 1036))
        + (unsigned int)v26;
    v28 = (unsigned int)v27 + (unsigned int)scnprintf(&v5[v27], 4096 - v27, "%25s\n", "==============");
    v29 = (unsigned int)scnprintf(&v5[v28], 4096 - v28, "%25s %10u\n", "OUT XferRscIndex: ", *(_DWORD *)(v2 + 544))
        + (unsigned int)v28;
    v30 = (unsigned int)scnprintf(&v5[v29], 4096 - v29, "%25s %10d\n", "OUT Channel Hdl: ", *(_DWORD *)(v2 + 536))
        + (unsigned int)v29;
    v31 = (unsigned int)scnprintf(&v5[v30], 4096 - v30, "%25s %10x\n", "OUT Channel Dbl Addr: ", *(_DWORD *)(v2 + 440))
        + (unsigned int)v30;
    v32 = (unsigned int)scnprintf(
                          &v5[v31],
                          4096 - v31,
                          "%25s %10u\n",
                          "OUT TRB Ring Len: ",
                          *(unsigned __int16 *)(v2 + 956))
        + (unsigned int)v31;
    v33 = (unsigned int)scnprintf(&v5[v32], 4096 - v32, "%25s %10x\n", "OUT TRB Base Addr: ", *(_DWORD *)(v2 + 976))
        + (unsigned int)v32;
    v34 = (unsigned int)scnprintf(&v5[v33], 4096 - v33, "%25s %10x\n", "GEVENTCNTLO OUT Addr: ", *(_DWORD *)(v2 + 944))
        + (unsigned int)v33;
    v35 = (unsigned int)scnprintf(&v5[v34], 4096 - v34, "%25s %10x\n", "DEPCMDLO OUT Addr: ", *(_DWORD *)(v2 + 964))
        + (unsigned int)v34;
    v36 = (unsigned int)scnprintf(
                          &v5[v35],
                          4096 - v35,
                          "%25s %10x\n",
                          "OUT LastTRB Addr Off: ",
                          *(unsigned __int16 *)(v2 + 960))
        + (unsigned int)v35;
    v37 = (unsigned int)scnprintf(
                          &v5[v36],
                          4096 - v36,
                          "%25s %10u\n",
                          "OUT Buffer Size: ",
                          *(unsigned __int8 *)(v2 + 962))
        + (unsigned int)v36;
    v38 = (unsigned int)scnprintf(&v5[v37], 4096 - v37, "%25s %10u\n", "OUT/UL Aggr Size: ", *(_DWORD *)(v2 + 1028))
        + (unsigned int)v37;
    v39 = (unsigned int)scnprintf(
                          &v5[v38],
                          4096 - v38,
                          "%25s %10u\n",
                          "OUT/UL Packets to dev: ",
                          *(_DWORD *)(v2 + 1032))
        + (unsigned int)v38;
    v40 = (unsigned int)scnprintf(
                          &v5[v39],
                          4096 - v39,
                          "%25s %10u\n",
                          "Net_ready_trigger:",
                          *(unsigned __int8 *)(v2 + 561))
        + (unsigned int)v39;
    v41 = 0;
    LODWORD(v42) = v40 + scnprintf(&v5[v40], 4096 - v40, "%25s\n", "USB Bus Events");
    do
    {
      v43 = scnprintf(
              &v5[(unsigned int)v42],
              4096LL - (unsigned int)v42,
              "%d\t",
              *(unsigned __int8 *)(v2 + 692 + v41++));
      v42 = (unsigned int)(v43 + v42);
    }
    while ( v41 != 128 );
    v44 = (unsigned int)scnprintf(&v5[v42], 4096 - v42, "\n") + (unsigned int)v42;
    v45 = (unsigned int)scnprintf(&v5[v44], 4096 - v44, "%25s %10u\n", "Eventq head: ", *(unsigned __int8 *)(v2 + 820))
        + (unsigned int)v44;
    v46 = scnprintf(&v5[v45], 4096 - v45, "%25s %10u\n", "Eventq tail: ", *(unsigned __int8 *)(v2 + 821)) + v45;
    if ( v46 >= 0x1000 )
      v47 = 4096;
    else
      v47 = v46;
  }
  else
  {
    v47 = 0;
  }
  v48 = scnprintf(a2, v47, v5);
  kfree(v5);
  return v48;
}
