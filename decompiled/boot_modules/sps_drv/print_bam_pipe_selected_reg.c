__int64 __fastcall print_bam_pipe_selected_reg(__int64 result, unsigned int a2)
{
  __int64 v3; // x22
  unsigned int reg; // w21
  unsigned int reg_field; // w20
  unsigned int v6; // w28
  unsigned int v7; // w27
  unsigned int v8; // w26
  unsigned int v9; // w25
  unsigned int v10; // w24
  unsigned int v11; // w23
  __int64 v12; // x8
  __int64 v13; // x8
  void *v14; // x0
  __int64 v15; // x2
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 v44; // x8
  __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x8
  __int64 v52; // x8
  __int64 v53; // x8
  __int64 v54; // x8
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x8
  __int64 v59; // x8
  __int64 v60; // x8
  __int64 v61; // x8
  __int64 v62; // x8
  __int64 v63; // x8
  unsigned int v64; // [xsp+0h] [xbp-A0h]
  unsigned int v65; // [xsp+4h] [xbp-9Ch]
  unsigned int v66; // [xsp+8h] [xbp-98h]
  unsigned int v67; // [xsp+Ch] [xbp-94h]
  unsigned int v68; // [xsp+10h] [xbp-90h]
  unsigned int v69; // [xsp+14h] [xbp-8Ch]
  unsigned int v70; // [xsp+18h] [xbp-88h]
  unsigned int v71; // [xsp+1Ch] [xbp-84h]
  unsigned int v72; // [xsp+20h] [xbp-80h]
  unsigned int v73; // [xsp+24h] [xbp-7Ch]
  unsigned int v74; // [xsp+28h] [xbp-78h]
  unsigned int v75; // [xsp+2Ch] [xbp-74h]
  unsigned int v76; // [xsp+30h] [xbp-70h]
  unsigned int v77; // [xsp+34h] [xbp-6Ch]
  unsigned int v78; // [xsp+38h] [xbp-68h]
  unsigned int v79; // [xsp+3Ch] [xbp-64h]
  unsigned int v80; // [xsp+40h] [xbp-60h]
  unsigned int v81; // [xsp+44h] [xbp-5Ch]
  unsigned int v82; // [xsp+48h] [xbp-58h]
  unsigned int v83; // [xsp+4Ch] [xbp-54h]
  unsigned int v84; // [xsp+50h] [xbp-50h]
  unsigned int v85; // [xsp+54h] [xbp-4Ch]
  unsigned int v86; // [xsp+58h] [xbp-48h]
  unsigned int v87; // [xsp+5Ch] [xbp-44h]
  unsigned int v88; // [xsp+60h] [xbp-40h]
  unsigned int v89; // [xsp+64h] [xbp-3Ch]
  unsigned int v90; // [xsp+68h] [xbp-38h]
  unsigned int v91; // [xsp+6Ch] [xbp-34h]
  unsigned int v92; // [xsp+70h] [xbp-30h]
  unsigned int v93; // [xsp+74h] [xbp-2Ch]
  unsigned int v94; // [xsp+78h] [xbp-28h]
  unsigned int v95; // [xsp+7Ch] [xbp-24h]
  unsigned int v96; // [xsp+80h] [xbp-20h]
  unsigned int v97; // [xsp+84h] [xbp-1Ch]
  unsigned int v98; // [xsp+88h] [xbp-18h]
  unsigned int v99; // [xsp+8Ch] [xbp-14h]
  unsigned int v100; // [xsp+90h] [xbp-10h]
  unsigned int v101; // [xsp+94h] [xbp-Ch]
  unsigned int v102; // [xsp+98h] [xbp-8h]
  unsigned int v103; // [xsp+9Ch] [xbp-4h]

  if ( !result )
    return result;
  v3 = result;
  reg = bam_read_reg(result, 0x1Cu);
  reg_field = bam_read_reg_field(v3, 0x1Cu, a2, 0x20u);
  v6 = bam_read_reg_field(v3, 0x1Cu, a2, 8u);
  v7 = bam_read_reg(v3, 0x21u);
  v8 = bam_read_reg(v3, 0x1Fu);
  v9 = bam_read_reg_field(v3, 0x1Fu, a2, 0x20u);
  v10 = bam_read_reg_field(v3, 0x1Fu, a2, 1u);
  v103 = bam_read_reg(v3, 0x24u);
  v102 = bam_read_reg_field(v3, 0x24u, a2, 0xFFFFu);
  v101 = bam_read_reg_field(v3, 0x24u, a2, 0xF0000u);
  v100 = bam_read_reg_field(v3, 0x24u, a2, 0x100000u);
  v99 = bam_read_reg_field(v3, 0x24u, a2, 0x1000000u);
  v98 = bam_read_reg(v3, 0x25u);
  v96 = bam_read_reg_field(v3, 0x25u, a2, 0xFFFFu);
  v95 = bam_read_reg_field(v3, 0x25u, a2, 0xF0000u);
  v94 = bam_read_reg_field(v3, 0x25u, a2, 0x100000u);
  v93 = bam_read_reg_field(v3, 0x25u, a2, 0x400000u);
  v92 = bam_read_reg_field(v3, 0x25u, a2, 0x200000u);
  v97 = bam_read_reg_field(v3, 0x25u, a2, 0x800000u);
  v91 = bam_read_reg_field(v3, 0x25u, a2, 0x1000000u);
  v90 = bam_read_reg(v3, 0x29u);
  v89 = bam_read_reg_field(v3, 0x29u, a2, 0xFFFFu);
  v88 = bam_read_reg(v3, 0x28u);
  v87 = bam_read_reg_field(v3, 0x28u, a2, 0xFFFFu);
  v68 = bam_read_reg(v3, 0x26u);
  v80 = bam_read_reg(v3, 0x2Cu);
  v65 = bam_read_reg_field(v3, 0x2Fu, a2, 0xFFFFu);
  v78 = bam_read_reg(v3, 0x2Au);
  v67 = bam_read_reg_field(v3, 0x2Fu, a2, 0xFFFF0000);
  v64 = bam_read_reg(v3, 0x2Fu);
  v69 = bam_read_reg(v3, 0x2Eu);
  v71 = bam_read_reg_field(v3, 0x2Eu, a2, 0xFFFFu);
  v86 = bam_read_reg(v3, 0x31u);
  v85 = bam_read_reg_field(v3, 0x31u, a2, 0xFFFF0000);
  v84 = bam_read_reg(v3, 0x32u);
  v83 = bam_read_reg_field(v3, 0x32u, a2, 0xFFFFu);
  v70 = bam_read_reg(v3, 0x34u);
  v72 = bam_read_reg(v3, 0x35u);
  v74 = bam_read_reg(v3, 0x36u);
  v75 = bam_read_reg(v3, 0x38u);
  v76 = bam_read_reg(v3, 0x39u);
  v66 = bam_read_reg(v3, 0x27u);
  v79 = bam_read_reg(v3, 0x2Du);
  v77 = bam_read_reg(v3, 0x2Bu);
  v73 = bam_read_reg(v3, 0x36u);
  v11 = bam_read_reg_field(v3, 0x1Cu, a2, 0x1F0000u);
  v82 = bam_read_reg(v3, 0x33u);
  result = bam_read_reg_field(v3, 0x33u, a2, 0xFFFFu);
  v81 = result;
  if ( sps )
  {
    result = ipc_log_string(
               *(_QWORD *)(sps + 280),
               "%s: \nsps:<pipe-begin> --- Registers of Pipe %d ---\n\n",
               "print_bam_pipe_selected_reg",
               a2);
    v12 = sps;
    if ( sps )
    {
      if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_24E29, "print_bam_pipe_selected_reg", a2), (v12 = sps) != 0) )
      {
        result = ipc_log_string(*(_QWORD *)(v12 + 280), "%s: BAM_P_CTRL: 0x%x\n", "print_bam_pipe_selected_reg", reg);
        v13 = sps;
        if ( sps )
        {
          if ( *(_QWORD *)(sps + 280)
            || (result = printk(&unk_29CFD, "print_bam_pipe_selected_reg", reg), (v13 = sps) != 0) )
          {
            result = ipc_log_string(
                       *(_QWORD *)(v13 + 280),
                       "%s:     SYS_MODE: %d\n",
                       "print_bam_pipe_selected_reg",
                       reg_field);
            if ( sps )
            {
              if ( !*(_QWORD *)(sps + 280) )
                result = printk(&unk_29FFD, "print_bam_pipe_selected_reg", reg_field);
            }
          }
        }
      }
    }
  }
  if ( v6 )
  {
    if ( !sps )
      return result;
    result = ipc_log_string(
               *(_QWORD *)(sps + 280),
               "%s:     DIRECTION:%d->Producer\n",
               "print_bam_pipe_selected_reg",
               v6);
    if ( !sps )
      return result;
    if ( !*(_QWORD *)(sps + 280) )
    {
      v14 = &unk_28BB7;
      v15 = v6;
      goto LABEL_123;
    }
  }
  else
  {
    if ( !sps )
      return result;
    result = ipc_log_string(
               *(_QWORD *)(sps + 280),
               "%s:     DIRECTION:%d->Consumer\n",
               "print_bam_pipe_selected_reg",
               0);
    if ( !sps )
      return result;
    if ( !*(_QWORD *)(sps + 280) )
    {
      v14 = &unk_2A908;
      v15 = 0;
LABEL_123:
      result = printk(v14, "print_bam_pipe_selected_reg", v15);
      v16 = sps;
      if ( !sps )
        return result;
      goto LABEL_19;
    }
  }
  v16 = sps;
  if ( !sps )
    return result;
LABEL_19:
  result = ipc_log_string(
             *(_QWORD *)(v16 + 280),
             "%s:     LOCK_GROUP: 0x%x (%d)\n",
             "print_bam_pipe_selected_reg",
             v11,
             v11);
  v17 = sps;
  if ( sps )
  {
    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_26E55, "print_bam_pipe_selected_reg", v11), (v17 = sps) != 0) )
    {
      result = ipc_log_string(*(_QWORD *)(v17 + 280), "%s: BAM_P_IRQ_EN: 0x%x\n", "print_bam_pipe_selected_reg", v7);
      v18 = sps;
      if ( sps )
      {
        if ( *(_QWORD *)(sps + 280)
          || (result = printk(&unk_265EC, "print_bam_pipe_selected_reg", v7), (v18 = sps) != 0) )
        {
          result = ipc_log_string(
                     *(_QWORD *)(v18 + 280),
                     "%s: BAM_P_IRQ_STTS: 0x%x\n",
                     "print_bam_pipe_selected_reg",
                     v8);
          v19 = sps;
          if ( sps )
          {
            if ( *(_QWORD *)(sps + 280)
              || (result = printk(&unk_276A0, "print_bam_pipe_selected_reg", v8), (v19 = sps) != 0) )
            {
              result = ipc_log_string(
                         *(_QWORD *)(v19 + 280),
                         "%s:     TRNSFR_END_IRQ(EOT): 0x%x\n",
                         "print_bam_pipe_selected_reg",
                         v9);
              v20 = sps;
              if ( sps )
              {
                if ( *(_QWORD *)(sps + 280)
                  || (result = printk(&unk_24E60, "print_bam_pipe_selected_reg", v9), (v20 = sps) != 0) )
                {
                  result = ipc_log_string(
                             *(_QWORD *)(v20 + 280),
                             "%s:     PRCSD_DESC_IRQ(INT): 0x%x\n",
                             "print_bam_pipe_selected_reg",
                             v10);
                  v21 = sps;
                  if ( sps )
                  {
                    if ( *(_QWORD *)(sps + 280)
                      || (result = printk(&unk_29D15, "print_bam_pipe_selected_reg", v10), (v21 = sps) != 0) )
                    {
                      result = ipc_log_string(
                                 *(_QWORD *)(v21 + 280),
                                 "%s: BAM_P_PRDCR_SDBND: 0x%x\n",
                                 "print_bam_pipe_selected_reg",
                                 v103);
                      v22 = sps;
                      if ( sps )
                      {
                        if ( *(_QWORD *)(sps + 280)
                          || (result = printk(&unk_227DE, "print_bam_pipe_selected_reg", v103), (v22 = sps) != 0) )
                        {
                          result = ipc_log_string(
                                     *(_QWORD *)(v22 + 280),
                                     "%s:     BYTES_FREE: 0x%x (%d)\n",
                                     "print_bam_pipe_selected_reg",
                                     v102,
                                     v102);
                          v23 = sps;
                          if ( sps )
                          {
                            if ( *(_QWORD *)(sps + 280)
                              || (result = printk(&unk_271B0, "print_bam_pipe_selected_reg", v102), (v23 = sps) != 0) )
                            {
                              result = ipc_log_string(
                                         *(_QWORD *)(v23 + 280),
                                         "%s:     CTRL: 0x%x\n",
                                         "print_bam_pipe_selected_reg",
                                         v101);
                              v24 = sps;
                              if ( sps )
                              {
                                if ( *(_QWORD *)(sps + 280)
                                  || (result = printk(&unk_25C81, "print_bam_pipe_selected_reg", v101), (v24 = sps) != 0) )
                                {
                                  result = ipc_log_string(
                                             *(_QWORD *)(v24 + 280),
                                             "%s:     TOGGLE: %d\n",
                                             "print_bam_pipe_selected_reg",
                                             v100);
                                  v25 = sps;
                                  if ( sps )
                                  {
                                    if ( *(_QWORD *)(sps + 280)
                                      || (result = printk(&unk_23C59, "print_bam_pipe_selected_reg", v100),
                                          (v25 = sps) != 0) )
                                    {
                                      result = ipc_log_string(
                                                 *(_QWORD *)(v25 + 280),
                                                 "%s:     SB_UPDATED: %d\n",
                                                 "print_bam_pipe_selected_reg",
                                                 v99);
                                      v26 = sps;
                                      if ( sps )
                                      {
                                        if ( *(_QWORD *)(sps + 280)
                                          || (result = printk(&unk_276BC, "print_bam_pipe_selected_reg", v99),
                                              (v26 = sps) != 0) )
                                        {
                                          result = ipc_log_string(
                                                     *(_QWORD *)(v26 + 280),
                                                     "%s: BAM_P_CNSMR_SDBND: 0x%x\n",
                                                     "print_bam_pipe_selected_reg",
                                                     v98);
                                          v27 = sps;
                                          if ( sps )
                                          {
                                            if ( *(_QWORD *)(sps + 280)
                                              || (result = printk(&unk_298D9, "print_bam_pipe_selected_reg", v98),
                                                  (v27 = sps) != 0) )
                                            {
                                              result = ipc_log_string(
                                                         *(_QWORD *)(v27 + 280),
                                                         "%s:     WAIT_4_ACK: %d\n",
                                                         "print_bam_pipe_selected_reg",
                                                         v97);
                                              v28 = sps;
                                              if ( sps )
                                              {
                                                if ( *(_QWORD *)(sps + 280)
                                                  || (result = printk(&unk_29221, "print_bam_pipe_selected_reg", v97),
                                                      (v28 = sps) != 0) )
                                                {
                                                  result = ipc_log_string(
                                                             *(_QWORD *)(v28 + 280),
                                                             "%s:     BYTES_AVAIL: 0x%x (%d)\n",
                                                             "print_bam_pipe_selected_reg",
                                                             v96,
                                                             v96);
                                                  v29 = sps;
                                                  if ( sps )
                                                  {
                                                    if ( *(_QWORD *)(sps + 280)
                                                      || (result = printk(
                                                                     &unk_25369,
                                                                     "print_bam_pipe_selected_reg",
                                                                     v96),
                                                          (v29 = sps) != 0) )
                                                    {
                                                      result = ipc_log_string(
                                                                 *(_QWORD *)(v29 + 280),
                                                                 "%s:     CTRL: 0x%x\n",
                                                                 "print_bam_pipe_selected_reg",
                                                                 v95);
                                                      v30 = sps;
                                                      if ( sps )
                                                      {
                                                        if ( *(_QWORD *)(sps + 280)
                                                          || (result = printk(
                                                                         &unk_25C81,
                                                                         "print_bam_pipe_selected_reg",
                                                                         v95),
                                                              (v30 = sps) != 0) )
                                                        {
                                                          result = ipc_log_string(
                                                                     *(_QWORD *)(v30 + 280),
                                                                     "%s:     TOGGLE: %d\n",
                                                                     "print_bam_pipe_selected_reg",
                                                                     v94);
                                                          v31 = sps;
                                                          if ( sps )
                                                          {
                                                            if ( *(_QWORD *)(sps + 280)
                                                              || (result = printk(
                                                                             &unk_23C59,
                                                                             "print_bam_pipe_selected_reg",
                                                                             v94),
                                                                  (v31 = sps) != 0) )
                                                            {
                                                              result = ipc_log_string(
                                                                         *(_QWORD *)(v31 + 280),
                                                                         "%s:     ACK_TOGGLE: %d\n",
                                                                         "print_bam_pipe_selected_reg",
                                                                         v93);
                                                              v32 = sps;
                                                              if ( sps )
                                                              {
                                                                if ( *(_QWORD *)(sps + 280)
                                                                  || (result = printk(
                                                                                 &unk_28812,
                                                                                 "print_bam_pipe_selected_reg",
                                                                                 v93),
                                                                      (v32 = sps) != 0) )
                                                                {
                                                                  result = ipc_log_string(
                                                                             *(_QWORD *)(v32 + 280),
                                                                             "%s:     ACK_TOGGLE_R: %d\n",
                                                                             "print_bam_pipe_selected_reg",
                                                                             v92);
                                                                  v33 = sps;
                                                                  if ( sps )
                                                                  {
                                                                    if ( *(_QWORD *)(sps + 280)
                                                                      || (result = printk(
                                                                                     &unk_2458A,
                                                                                     "print_bam_pipe_selected_reg",
                                                                                     v92),
                                                                          (v33 = sps) != 0) )
                                                                    {
                                                                      result = ipc_log_string(
                                                                                 *(_QWORD *)(v33 + 280),
                                                                                 "%s:     SB_UPDATED: %d\n",
                                                                                 "print_bam_pipe_selected_reg",
                                                                                 v91);
                                                                      v34 = sps;
                                                                      if ( sps )
                                                                      {
                                                                        if ( *(_QWORD *)(sps + 280)
                                                                          || (result = printk(
                                                                                         &unk_276BC,
                                                                                         "print_bam_pipe_selected_reg",
                                                                                         v91),
                                                                              (v34 = sps) != 0) )
                                                                        {
                                                                          result = ipc_log_string(
                                                                                     *(_QWORD *)(v34 + 280),
                                                                                     "%s: BAM_P_SW_DESC_OFST: 0x%x\n",
                                                                                     "print_bam_pipe_selected_reg",
                                                                                     v90);
                                                                          v35 = sps;
                                                                          if ( sps )
                                                                          {
                                                                            if ( *(_QWORD *)(sps + 280)
                                                                              || (result = printk(
                                                                                             &unk_27EFE,
                                                                                             "print_bam_pipe_selected_reg",
                                                                                             v90),
                                                                                  (v35 = sps) != 0) )
                                                                            {
                                                                              result = ipc_log_string(
                                                                                         *(_QWORD *)(v35 + 280),
                                                                                         "%s:     SW_DESC_OFST: 0x%x\n",
                                                                                         "print_bam_pipe_selected_reg",
                                                                                         v89);
                                                                              v36 = sps;
                                                                              if ( sps )
                                                                              {
                                                                                if ( *(_QWORD *)(sps + 280)
                                                                                  || (result = printk(
                                                                                                 &unk_22C7B,
                                                                                                 "print_bam_pipe_selected_reg",
                                                                                                 v89),
                                                                                      (v36 = sps) != 0) )
                                                                                {
                                                                                  result = ipc_log_string(
                                                                                             *(_QWORD *)(v36 + 280),
                                                                                             "%s: BAM_P_EVNT_REG: 0x%x\n",
                                                                                             "print_bam_pipe_selected_reg",
                                                                                             v88);
                                                                                  v37 = sps;
                                                                                  if ( sps )
                                                                                  {
                                                                                    if ( *(_QWORD *)(sps + 280)
                                                                                      || (result = printk(
                                                                                                     &unk_2A533,
                                                                                                     "print_bam_pipe_selected_reg",
                                                                                                     v88),
                                                                                          (v37 = sps) != 0) )
                                                                                    {
                                                                                      result = ipc_log_string(
                                                                                                 *(_QWORD *)(v37 + 280),
                                                                                                 "%s:     DESC_FIFO_PEER_OFST: 0x%x\n",
                                                                                                 "print_bam_pipe_selected_reg",
                                                                                                 v87);
                                                                                      v38 = sps;
                                                                                      if ( sps )
                                                                                      {
                                                                                        if ( *(_QWORD *)(sps + 280)
                                                                                          || (result = printk(&unk_24E85, "print_bam_pipe_selected_reg", v87),
                                                                                              (v38 = sps) != 0) )
                                                                                        {
                                                                                          result = ipc_log_string(
                                                                                                     *(_QWORD *)(v38 + 280),
                                                                                                     "%s: BAM_P_RETR_CNTXT: 0x%x\n",
                                                                                                     "print_bam_pipe_selected_reg",
                                                                                                     v86);
                                                                                          v39 = sps;
                                                                                          if ( sps )
                                                                                          {
                                                                                            if ( *(_QWORD *)(sps + 280)
                                                                                              || (result = printk(&unk_2409E, "print_bam_pipe_selected_reg", v86),
                                                                                                  (v39 = sps) != 0) )
                                                                                            {
                                                                                              result = ipc_log_string(*(_QWORD *)(v39 + 280), "%s:     RETR_OFFSET: 0x%x\n", "print_bam_pipe_selected_reg", v85);
                                                                                              v40 = sps;
                                                                                              if ( sps )
                                                                                              {
                                                                                                if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_276D6, "print_bam_pipe_selected_reg", v85), (v40 = sps) != 0) )
                                                                                                {
                                                                                                  result = ipc_log_string(*(_QWORD *)(v40 + 280), "%s: BAM_P_SI_CNTXT: 0x%x\n", "print_bam_pipe_selected_reg", v84);
                                                                                                  v41 = sps;
                                                                                                  if ( sps )
                                                                                                  {
                                                                                                    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_2696B, "print_bam_pipe_selected_reg", v84), (v41 = sps) != 0) )
                                                                                                    {
                                                                                                      result = ipc_log_string(*(_QWORD *)(v41 + 280), "%s:     SI_OFFSET: 0x%x\n", "print_bam_pipe_selected_reg", v83);
                                                                                                      v42 = sps;
                                                                                                      if ( sps )
                                                                                                      {
                                                                                                        if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_28C14, "print_bam_pipe_selected_reg", v83), (v42 = sps) != 0) )
                                                                                                        {
                                                                                                          result = ipc_log_string(*(_QWORD *)(v42 + 280), "%s: BAM_P_DF_CNTXT: 0x%x\n", "print_bam_pipe_selected_reg", v82);
                                                                                                          v43 = sps;
                                                                                                          if ( sps )
                                                                                                          {
                                                                                                            if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_2882C, "print_bam_pipe_selected_reg", v82), (v43 = sps) != 0) )
                                                                                                            {
                                                                                                              result = ipc_log_string(*(_QWORD *)(v43 + 280), "%s:     DF_OFFSET: 0x%x\n", "print_bam_pipe_selected_reg", v81);
                                                                                                              v44 = sps;
                                                                                                              if ( sps )
                                                                                                              {
                                                                                                                if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_227FD, "print_bam_pipe_selected_reg", v81), (v44 = sps) != 0) )
                                                                                                                {
                                                                                                                  result = ipc_log_string(*(_QWORD *)(v44 + 280), "%s: BAM_P_DESC_FIFO_ADDR: 0x%x\n", "print_bam_pipe_selected_reg", v80);
                                                                                                                  v45 = sps;
                                                                                                                  if ( sps )
                                                                                                                  {
                                                                                                                    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_29D5D, "print_bam_pipe_selected_reg", v80), (v45 = sps) != 0) )
                                                                                                                    {
                                                                                                                      result = ipc_log_string(*(_QWORD *)(v45 + 280), "%s: BAM_P_DESC_FIFO_ADDR_MSB: 0x%x\n", "print_bam_pipe_selected_reg", v79);
                                                                                                                      v46 = sps;
                                                                                                                      if ( sps )
                                                                                                                      {
                                                                                                                        if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_2991C, "print_bam_pipe_selected_reg", v79), (v46 = sps) != 0) )
                                                                                                                        {
                                                                                                                          result = ipc_log_string(*(_QWORD *)(v46 + 280), "%s: BAM_P_DATA_FIFO_ADDR: 0x%x\n", "print_bam_pipe_selected_reg", v78);
                                                                                                                          v47 = sps;
                                                                                                                          if ( sps )
                                                                                                                          {
                                                                                                                            if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_240BC, "print_bam_pipe_selected_reg", v78), (v47 = sps) != 0) )
                                                                                                                            {
                                                                                                                              result = ipc_log_string(*(_QWORD *)(v47 + 280), "%s: BAM_P_DATA_FIFO_ADDR_MSB: 0x%x\n", "print_bam_pipe_selected_reg", v77);
                                                                                                                              v48 = sps;
                                                                                                                              if ( sps )
                                                                                                                              {
                                                                                                                                if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_276F3, "print_bam_pipe_selected_reg", v77), (v48 = sps) != 0) )
                                                                                                                                {
                                                                                                                                  result = ipc_log_string(*(_QWORD *)(v48 + 280), "%s: BAM_P_FIFO_SIZES: 0x%x\n", "print_bam_pipe_selected_reg", v64);
                                                                                                                                  v49 = sps;
                                                                                                                                  if ( sps )
                                                                                                                                  {
                                                                                                                                    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_284E1, "print_bam_pipe_selected_reg", v64), (v49 = sps) != 0) )
                                                                                                                                    {
                                                                                                                                      result = ipc_log_string(*(_QWORD *)(v49 + 280), "%s:     DESC_FIFO_SIZE: 0x%x (%d)\n", "print_bam_pipe_selected_reg", v65, v65);
                                                                                                                                      v50 = sps;
                                                                                                                                      if ( sps )
                                                                                                                                      {
                                                                                                                                        if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_24EAA, "print_bam_pipe_selected_reg", v65), (v50 = sps) != 0) )
                                                                                                                                        {
                                                                                                                                          result = ipc_log_string(*(_QWORD *)(v50 + 280), "%s:     DATA_FIFO_SIZE: 0x%x (%d)\n", "print_bam_pipe_selected_reg", v67, v67);
                                                                                                                                          v51 = sps;
                                                                                                                                          if ( sps )
                                                                                                                                          {
                                                                                                                                            if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_24958, "print_bam_pipe_selected_reg", v67), (v51 = sps) != 0) )
                                                                                                                                            {
                                                                                                                                              result = ipc_log_string(*(_QWORD *)(v51 + 280), "%s: BAM_P_EVNT_DEST_ADDR: 0x%x\n", "print_bam_pipe_selected_reg", v68);
                                                                                                                                              v52 = sps;
                                                                                                                                              if ( sps )
                                                                                                                                              {
                                                                                                                                                if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_2538B, "print_bam_pipe_selected_reg", v68), (v52 = sps) != 0) )
                                                                                                                                                {
                                                                                                                                                  result = ipc_log_string(*(_QWORD *)(v52 + 280), "%s: BAM_P_EVNT_DEST_ADDR_MSB: 0x%x\n", "print_bam_pipe_selected_reg", v66);
                                                                                                                                                  v53 = sps;
                                                                                                                                                  if ( sps )
                                                                                                                                                  {
                                                                                                                                                    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_26606, "print_bam_pipe_selected_reg", v66), (v53 = sps) != 0) )
                                                                                                                                                    {
                                                                                                                                                      result = ipc_log_string(*(_QWORD *)(v53 + 280), "%s: BAM_P_EVNT_GEN_TRSHLD: 0x%x\n", "print_bam_pipe_selected_reg", v69);
                                                                                                                                                      v54 = sps;
                                                                                                                                                      if ( sps )
                                                                                                                                                      {
                                                                                                                                                        if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_26E76, "print_bam_pipe_selected_reg", v69), (v54 = sps) != 0) )
                                                                                                                                                        {
                                                                                                                                                          result = ipc_log_string(*(_QWORD *)(v54 + 280), "%s:     EVNT_GEN_TRSHLD: 0x%x (%d)\n", "print_bam_pipe_selected_reg", v71, v71);
                                                                                                                                                          v55 = sps;
                                                                                                                                                          if ( sps )
                                                                                                                                                          {
                                                                                                                                                            if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_25790, "print_bam_pipe_selected_reg", v71), (v55 = sps) != 0) )
                                                                                                                                                            {
                                                                                                                                                              result = ipc_log_string(*(_QWORD *)(v55 + 280), "%s: BAM_P_AU_PSM_CNTXT_1: 0x%x\n", "print_bam_pipe_selected_reg", v70);
                                                                                                                                                              v56 = sps;
                                                                                                                                                              if ( sps )
                                                                                                                                                              {
                                                                                                                                                                if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_2612E, "print_bam_pipe_selected_reg", v70), (v56 = sps) != 0) )
                                                                                                                                                                {
                                                                                                                                                                  result = ipc_log_string(*(_QWORD *)(v56 + 280), "%s: BAM_P_PSM_CNTXT_2: 0x%x\n", "print_bam_pipe_selected_reg", v72);
                                                                                                                                                                  v57 = sps;
                                                                                                                                                                  if ( sps )
                                                                                                                                                                  {
                                                                                                                                                                    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_2497D, "print_bam_pipe_selected_reg", v72), (v57 = sps) != 0) )
                                                                                                                                                                    {
                                                                                                                                                                      result = ipc_log_string(*(_QWORD *)(v57 + 280), "%s: BAM_P_PSM_CNTXT_3: 0x%x\n", "print_bam_pipe_selected_reg", v74);
                                                                                                                                                                      v58 = sps;
                                                                                                                                                                      if ( sps )
                                                                                                                                                                      {
                                                                                                                                                                        if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_28848, "print_bam_pipe_selected_reg", v74), (v58 = sps) != 0) )
                                                                                                                                                                        {
                                                                                                                                                                          result = ipc_log_string(*(_QWORD *)(v58 + 280), "%s: BAM_P_PSM_CNTXT_3_MSB: 0x%x\n", "print_bam_pipe_selected_reg", v73);
                                                                                                                                                                          v59 = sps;
                                                                                                                                                                          if ( sps )
                                                                                                                                                                          {
                                                                                                                                                                            if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_257B6, "print_bam_pipe_selected_reg", v73), (v59 = sps) != 0) )
                                                                                                                                                                            {
                                                                                                                                                                              result = ipc_log_string(*(_QWORD *)(v59 + 280), "%s: BAM_P_PSM_CNTXT_4: 0x%x\n", "print_bam_pipe_selected_reg", v75);
                                                                                                                                                                              v60 = sps;
                                                                                                                                                                              if ( sps )
                                                                                                                                                                              {
                                                                                                                                                                                if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_2B01D, "print_bam_pipe_selected_reg", v75), (v60 = sps) != 0) )
                                                                                                                                                                                {
                                                                                                                                                                                  result = ipc_log_string(*(_QWORD *)(v60 + 280), "%s: BAM_P_PSM_CNTXT_5: 0x%x\n", "print_bam_pipe_selected_reg", v76);
                                                                                                                                                                                  v61 = sps;
                                                                                                                                                                                  if ( sps )
                                                                                                                                                                                  {
                                                                                                                                                                                    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_26E99, "print_bam_pipe_selected_reg", v76), (v61 = sps) != 0) )
                                                                                                                                                                                    {
                                                                                                                                                                                      result = ipc_log_string(*(_QWORD *)(v61 + 280), "%s: BAM_P_TIMER: 0x%x\n", "print_bam_pipe_selected_reg", 0);
                                                                                                                                                                                      v62 = sps;
                                                                                                                                                                                      if ( sps )
                                                                                                                                                                                      {
                                                                                                                                                                                        if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_27757, "print_bam_pipe_selected_reg", 0), (v62 = sps) != 0) )
                                                                                                                                                                                        {
                                                                                                                                                                                          result = ipc_log_string(*(_QWORD *)(v62 + 280), "%s: BAM_P_TIMER_CTRL: 0x%x\n", "print_bam_pipe_selected_reg", 0);
                                                                                                                                                                                          v63 = sps;
                                                                                                                                                                                          if ( sps )
                                                                                                                                                                                          {
                                                                                                                                                                                            if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_284FF, "print_bam_pipe_selected_reg", 0), (v63 = sps) != 0) )
                                                                                                                                                                                            {
                                                                                                                                                                                              result = ipc_log_string(*(_QWORD *)(v63 + 280), "%s: \nsps:<pipe-end> --- Registers of Pipe %d ---\n\n", "print_bam_pipe_selected_reg", a2);
                                                                                                                                                                                              if ( sps )
                                                                                                                                                                                              {
                                                                                                                                                                                                if ( !*(_QWORD *)(sps + 280) )
                                                                                                                                                                                                  return printk(&unk_2A051, "print_bam_pipe_selected_reg", a2);
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
          }
        }
      }
    }
  }
  return result;
}
