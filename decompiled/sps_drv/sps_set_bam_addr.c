__int64 __fastcall sps_set_bam_addr(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  unsigned int v4; // w0
  __int64 v5; // x2
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x20
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 v13; // x22
  unsigned int v14; // w20
  __int64 v15; // x20
  unsigned __int64 v16; // x8
  __int64 v17; // x20
  unsigned __int64 v18; // x8
  unsigned int v19; // w1
  __int64 v20; // x20
  unsigned __int64 v21; // x8
  __int64 v22; // x20
  unsigned __int64 v23; // x8
  __int64 v24; // x20
  unsigned __int64 v25; // x8
  __int64 v26; // x20
  unsigned __int64 v27; // x8
  unsigned int v28; // w20
  unsigned int v29; // w20
  __int64 v30; // x20
  unsigned __int64 v31; // x8
  __int64 v32; // x20
  unsigned __int64 v33; // x8
  __int64 v34; // x20
  unsigned __int64 v35; // x8
  unsigned int v36; // w20
  __int64 v37; // x20
  unsigned __int64 v38; // x8
  unsigned int v39; // w20
  __int64 v40; // x20
  unsigned __int64 v41; // x8
  __int64 v42; // x20
  unsigned __int64 v43; // x8
  __int64 v44; // x20
  unsigned __int64 v45; // x8
  unsigned int v46; // w20
  unsigned int v47; // w20
  unsigned int v48; // w20
  unsigned int v49; // w20
  unsigned __int64 v50; // x8
  __int64 i; // x20
  unsigned __int64 v52; // x8
  __int64 j; // x20
  unsigned __int64 v54; // x8
  __int64 k; // x20
  unsigned __int64 v56; // x8
  __int64 m; // x20
  unsigned int v58; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  v4 = kstrtouint_from_user(a2, a3, 10, &v58);
  if ( v4 )
  {
    v3 = v4;
  }
  else
  {
    printk(&unk_24B8A, v58, v5);
    v9 = v58;
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&phy2bam__rs, "phy2bam")) )
    {
      printk(&unk_26A3F, "phy2bam", v8);
    }
    v10 = sps;
    if ( sps && *(_DWORD *)(sps + 288) <= 2u )
    {
      ipc_log_string(*(_QWORD *)(sps + 264), "%s: Enter\n", "phy2bam");
      v10 = sps;
    }
    v11 = v10 + 160;
    v12 = v11;
    do
    {
      v12 = *(_QWORD *)v12;
      if ( v12 == v11 )
        goto LABEL_19;
    }
    while ( *(_QWORD *)(v12 + 24) != v9 );
    if ( !v12 )
    {
LABEL_19:
      printk(&unk_229BF, v58, v8);
      goto LABEL_3;
    }
    if ( (unsigned int)log_level_sel <= 4 )
      *(_DWORD *)(v12 + 568) = log_level_sel;
    v13 = *(unsigned int *)(v12 + 48);
    switch ( reg_dump_option )
    {
      case 1:
        print_bam_reg(*(_DWORD **)(v12 + 216));
        if ( (_DWORD)v13 )
        {
          v14 = 0;
          do
            print_bam_pipe_reg(*(_QWORD *)(v12 + 216), v14++);
          while ( (_DWORD)v13 != v14 );
        }
        break;
      case 2:
        print_bam_reg(*(_DWORD **)(v12 + 216));
        break;
      case 3:
        goto LABEL_125;
      case 4:
        if ( (_DWORD)v13 )
        {
          v28 = 0;
          do
            print_bam_pipe_selected_reg(v12 + 216, v28++);
          while ( (_DWORD)v13 != v28 );
        }
        break;
      case 5:
        if ( (_DWORD)v13 )
        {
          v24 = 0;
          v25 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v25 >> v24) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v24);
              v25 = (unsigned int)bam_pipe_sel;
            }
            ++v24;
          }
          while ( v13 != v24 );
        }
        break;
      case 6:
        print_bam_pipe_selected_reg(v12 + 216, 4u);
        print_bam_pipe_selected_reg(v12 + 216, 5u);
        break;
      case 7:
        if ( (_DWORD)v13 )
        {
          v29 = 0;
          do
            print_bam_pipe_desc_fifo(v12 + 216, v29++, 0);
          while ( (_DWORD)v13 != v29 );
        }
        break;
      case 8:
        if ( (_DWORD)v13 )
        {
          v26 = 0;
          v27 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v27 >> v26) & 1) != 0 )
            {
              print_bam_pipe_desc_fifo(v12 + 216, v26, 0);
              v27 = (unsigned int)bam_pipe_sel;
            }
            ++v26;
          }
          while ( v13 != v26 );
        }
        break;
      case 9:
        print_bam_pipe_desc_fifo(v12 + 216, 4u, 0);
        goto LABEL_82;
      case 10:
        if ( (_DWORD)v13 )
        {
          v36 = 0;
          do
          {
            print_bam_pipe_selected_reg(v12 + 216, v36);
            print_bam_pipe_desc_fifo(v12 + 216, v36++, 0);
          }
          while ( (_DWORD)v13 != v36 );
        }
        break;
      case 11:
        if ( (_DWORD)v13 )
        {
          v15 = 0;
          v16 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v16 >> v15) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v15);
              print_bam_pipe_desc_fifo(v12 + 216, v15, 0);
              v16 = (unsigned int)bam_pipe_sel;
            }
            ++v15;
          }
          while ( v13 != v15 );
        }
        break;
      case 12:
        print_bam_pipe_selected_reg(v12 + 216, 4u);
        print_bam_pipe_desc_fifo(v12 + 216, 4u, 0);
        print_bam_pipe_selected_reg(v12 + 216, 5u);
LABEL_82:
        print_bam_pipe_desc_fifo(v12 + 216, 5u, 0);
        break;
      case 13:
        v19 = testbus_sel;
        if ( !testbus_sel )
        {
          printk(&unk_254FA, 0, v8);
          v19 = testbus_sel;
        }
        print_bam_test_bus_reg(v12 + 216, v19);
        break;
      case 14:
        if ( !desc_option )
          desc_option = 1;
        if ( (_DWORD)v13 )
        {
          v40 = 0;
          v41 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v41 >> v40) & 1) != 0 )
            {
              print_bam_pipe_desc_fifo(v12 + 216, v40, desc_option);
              v41 = (unsigned int)bam_pipe_sel;
            }
            ++v40;
          }
          while ( v13 != v40 );
        }
        break;
      case 15:
        if ( (_DWORD)v13 )
        {
          v37 = 0;
          v38 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v38 >> v37) & 1) != 0 )
            {
              print_bam_pipe_desc_fifo(v12 + 216, v37, 100);
              v38 = (unsigned int)bam_pipe_sel;
            }
            ++v37;
          }
          while ( v13 != v37 );
        }
        break;
      case 16:
        if ( (_DWORD)v13 )
        {
          v17 = 0;
          v18 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v18 >> v17) & 1) != 0 )
            {
              print_bam_pipe_reg(*(_QWORD *)(v12 + 216), v17);
              v18 = (unsigned int)bam_pipe_sel;
            }
            ++v17;
          }
          while ( v13 != v17 );
        }
        break;
      case 91:
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        if ( (_DWORD)v13 )
        {
          v39 = 0;
          do
            print_bam_pipe_selected_reg(v12 + 216, v39++);
          while ( (_DWORD)v13 != v39 );
        }
        break;
      case 92:
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        if ( (_DWORD)v13 )
        {
          v20 = 0;
          v21 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v21 >> v20) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v20);
              v21 = (unsigned int)bam_pipe_sel;
            }
            ++v20;
          }
          while ( v13 != v20 );
        }
        break;
      case 93:
        if ( !desc_option )
          desc_option = 1;
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        if ( (_DWORD)v13 )
        {
          v22 = 0;
          v23 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v23 >> v22) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v22);
              v23 = (unsigned int)bam_pipe_sel;
            }
            ++v22;
          }
          while ( v13 != v22 );
          v50 = (unsigned int)bam_pipe_sel;
          for ( i = 0; i != v13; ++i )
          {
            if ( ((v50 >> i) & 1) != 0 )
            {
              print_bam_pipe_desc_fifo(v12 + 216, i, desc_option);
              v50 = (unsigned int)bam_pipe_sel;
            }
          }
        }
        break;
      case 94:
        if ( !desc_option )
          desc_option = 1;
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        if ( (_DWORD)v13 )
        {
          v42 = 0;
          v43 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v43 >> v42) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v42);
              print_bam_pipe_desc_fifo(v12 + 216, v42, desc_option);
              v43 = (unsigned int)bam_pipe_sel;
            }
            ++v42;
          }
          while ( v13 != v42 );
        }
        break;
      case 95:
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        if ( (_DWORD)v13 )
        {
          v32 = 0;
          v33 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v33 >> v32) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v32);
              v33 = (unsigned int)bam_pipe_sel;
            }
            ++v32;
          }
          while ( v13 != v32 );
          v52 = (unsigned int)bam_pipe_sel;
          for ( j = 0; j != v13; ++j )
          {
            if ( ((v52 >> j) & 1) != 0 )
            {
              print_bam_pipe_desc_fifo(v12 + 216, j, 0);
              v52 = (unsigned int)bam_pipe_sel;
            }
          }
        }
        break;
      case 96:
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        if ( (_DWORD)v13 )
        {
          v30 = 0;
          v31 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v31 >> v30) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v30);
              print_bam_pipe_desc_fifo(v12 + 216, v30, 0);
              v31 = (unsigned int)bam_pipe_sel;
            }
            ++v30;
          }
          while ( v13 != v30 );
        }
        break;
      case 97:
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        if ( (_DWORD)v13 )
        {
          v44 = 0;
          v45 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v45 >> v44) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v44);
              v45 = (unsigned int)bam_pipe_sel;
            }
            ++v44;
          }
          while ( v13 != v44 );
          v54 = (unsigned int)bam_pipe_sel;
          for ( k = 0; k != v13; ++k )
          {
            if ( ((v54 >> k) & 1) != 0 )
            {
              print_bam_pipe_desc_fifo(v12 + 216, k, 0);
              v54 = (unsigned int)bam_pipe_sel;
            }
          }
          v56 = (unsigned int)bam_pipe_sel;
          for ( m = 0; m != v13; ++m )
          {
            if ( ((v56 >> m) & 1) != 0 )
            {
              print_bam_pipe_desc_fifo(v12 + 216, m, 100);
              v56 = (unsigned int)bam_pipe_sel;
            }
          }
        }
        break;
      case 98:
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        if ( (_DWORD)v13 )
        {
          v34 = 0;
          v35 = (unsigned int)bam_pipe_sel;
          do
          {
            if ( ((v35 >> v34) & 1) != 0 )
            {
              print_bam_pipe_selected_reg(v12 + 216, v34);
              print_bam_pipe_desc_fifo(v12 + 216, v34, 0);
              print_bam_pipe_desc_fifo(v12 + 216, v34, 100);
              v35 = (unsigned int)bam_pipe_sel;
            }
            ++v34;
          }
          while ( v13 != v34 );
        }
        break;
      case 99:
        print_bam_test_bus_reg(v12 + 216, testbus_sel);
        print_bam_reg(*(_DWORD **)(v12 + 216));
        if ( (_DWORD)v13 )
        {
          v46 = 0;
          do
            print_bam_pipe_reg(*(_QWORD *)(v12 + 216), v46++);
          while ( (_DWORD)v13 != v46 );
          print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
          v47 = 0;
          do
            print_bam_pipe_selected_reg(v12 + 216, v47++);
          while ( (_DWORD)v13 != v47 );
          v48 = 0;
          do
            print_bam_pipe_desc_fifo(v12 + 216, v48++, 0);
          while ( (_DWORD)v13 != v48 );
          v49 = 0;
          do
            print_bam_pipe_desc_fifo(v12 + 216, v49++, 100);
          while ( (_DWORD)v13 != v49 );
        }
        else
        {
LABEL_125:
          print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
        }
        break;
      default:
        printk(&unk_28E9A, v7, v8);
        break;
    }
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v3;
}
