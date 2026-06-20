__int64 __fastcall sps_get_bam_debug_info(__int64 a1, int a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  unsigned int v9; // w23
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x19
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x22
  unsigned int v16; // w20
  __int64 result; // x0
  __int64 k; // x20
  __int64 ii; // x20
  __int64 jj; // x20
  int v21; // w21
  __int64 kk; // x20
  __int64 i; // x20
  __int64 j; // x20
  unsigned int v25; // w20
  unsigned int v26; // w20
  __int64 i3; // x20
  __int64 i1; // x20
  __int64 i7; // x20
  unsigned int v30; // w20
  __int64 n; // x20
  unsigned int v32; // w20
  int v33; // w20
  __int64 m; // x21
  int v35; // w21
  __int64 nn; // x20
  __int64 i4; // x20
  unsigned int v38; // w20
  unsigned int v39; // w20
  unsigned int v40; // w20
  unsigned int v41; // w20
  __int64 mm; // x20
  __int64 i2; // x20
  __int64 i5; // x20
  __int64 i6; // x20
  void *v46; // x0

  if ( a1 )
  {
    if ( sps && *(_DWORD *)(sps + 48) )
    {
      v9 = a3;
      mutex_lock(sps + 112);
      v10 = sps_h2bam(a1);
      if ( v10 )
      {
        v12 = v10;
        mutex_unlock(sps + 112);
        v15 = *(unsigned int *)(v12 + 48);
        if ( sps )
        {
          ipc_log_string(
            *(_QWORD *)(sps + 280),
            "%s: sps:<bam-addr> dump BAM:%pa\n",
            "sps_get_bam_debug_info",
            (const void *)(v12 + 24));
          if ( sps )
          {
            if ( !*(_QWORD *)(sps + 280) )
              printk(&unk_28CF3, "sps_get_bam_debug_info", v12 + 24);
          }
        }
        switch ( a2 )
        {
          case 1:
            print_bam_reg(*(_DWORD **)(v12 + 216));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            v16 = 0;
            do
            {
              print_bam_pipe_reg(*(_QWORD *)(v12 + 216), v16++);
              result = 0;
            }
            while ( (_DWORD)v15 != v16 );
            return result;
          case 2:
            print_bam_reg(*(_DWORD **)(v12 + 216));
            goto LABEL_134;
          case 3:
            goto LABEL_133;
          case 4:
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            v25 = 0;
            do
            {
              print_bam_pipe_selected_reg(v12 + 216, v25++);
              result = 0;
            }
            while ( (_DWORD)v15 != v25 );
            return result;
          case 5:
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( i = 0; i != v15; ++i )
            {
              if ( (((unsigned __int64)v9 >> i) & 1) != 0 )
                print_bam_pipe_selected_reg(v12 + 216, i);
              result = 0;
            }
            return result;
          case 6:
            print_bam_pipe_selected_reg(v12 + 216, 4u);
            print_bam_pipe_selected_reg(v12 + 216, 5u);
            goto LABEL_134;
          case 7:
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            v26 = 0;
            do
            {
              print_bam_pipe_desc_fifo(v12 + 216, v26++, 0);
              result = 0;
            }
            while ( (_DWORD)v15 != v26 );
            return result;
          case 8:
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( j = 0; j != v15; ++j )
            {
              if ( (((unsigned __int64)v9 >> j) & 1) != 0 )
                print_bam_pipe_desc_fifo(v12 + 216, j, 0);
              result = 0;
            }
            return result;
          case 9:
            print_bam_pipe_desc_fifo(v12 + 216, 4u, 0);
            goto LABEL_88;
          case 10:
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            v30 = 0;
            do
            {
              print_bam_pipe_selected_reg(v12 + 216, v30);
              print_bam_pipe_desc_fifo(v12 + 216, v30++, 0);
              result = 0;
            }
            while ( (_DWORD)v15 != v30 );
            return result;
          case 11:
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( k = 0; k != v15; ++k )
            {
              if ( (((unsigned __int64)v9 >> k) & 1) != 0 )
              {
                print_bam_pipe_selected_reg(v12 + 216, k);
                print_bam_pipe_desc_fifo(v12 + 216, k, 0);
              }
              result = 0;
            }
            return result;
          case 12:
            print_bam_pipe_selected_reg(v12 + 216, 4u);
            print_bam_pipe_desc_fifo(v12 + 216, 4u, 0);
            print_bam_pipe_selected_reg(v12 + 216, 5u);
LABEL_88:
            print_bam_pipe_desc_fifo(v12 + 216, 5u, 0);
            goto LABEL_134;
          case 13:
            if ( a4 )
            {
              print_bam_test_bus_reg(v12 + 216, a4);
            }
            else
            {
              v46 = &unk_2A58E;
LABEL_154:
              printk(v46, v13, v14);
            }
            goto LABEL_134;
          case 14:
            if ( a5 <= 1 )
              v33 = 1;
            else
              v33 = a5;
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( m = 0; m != v15; ++m )
            {
              if ( (((unsigned __int64)v9 >> m) & 1) != 0 )
                print_bam_pipe_desc_fifo(v12 + 216, m, v33);
              result = 0;
            }
            return result;
          case 15:
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( n = 0; n != v15; ++n )
            {
              if ( (((unsigned __int64)v9 >> n) & 1) != 0 )
                print_bam_pipe_desc_fifo(v12 + 216, n, 100);
              result = 0;
            }
            return result;
          case 16:
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( ii = 0; ii != v15; ++ii )
            {
              if ( (((unsigned __int64)v9 >> ii) & 1) != 0 )
                print_bam_pipe_reg(*(_QWORD *)(v12 + 216), ii);
              result = 0;
            }
            return result;
          case 91:
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            v32 = 0;
            do
            {
              print_bam_pipe_selected_reg(v12 + 216, v32++);
              result = 0;
            }
            while ( (_DWORD)v15 != v32 );
            return result;
          case 92:
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( jj = 0; jj != v15; ++jj )
            {
              if ( (((unsigned __int64)v9 >> jj) & 1) != 0 )
                print_bam_pipe_selected_reg(v12 + 216, jj);
              result = 0;
            }
            return result;
          case 93:
            if ( a5 <= 1 )
              v21 = 1;
            else
              v21 = a5;
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( kk = 0; kk != v15; ++kk )
            {
              if ( (((unsigned __int64)v9 >> kk) & 1) != 0 )
                print_bam_pipe_selected_reg(v12 + 216, kk);
            }
            for ( mm = 0; mm != v15; ++mm )
            {
              if ( (((unsigned __int64)v9 >> mm) & 1) != 0 )
                print_bam_pipe_desc_fifo(v12 + 216, mm, v21);
              result = 0;
            }
            return result;
          case 94:
            if ( a5 <= 1 )
              v35 = 1;
            else
              v35 = a5;
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( nn = 0; nn != v15; ++nn )
            {
              if ( (((unsigned __int64)v9 >> nn) & 1) != 0 )
              {
                print_bam_pipe_selected_reg(v12 + 216, nn);
                print_bam_pipe_desc_fifo(v12 + 216, nn, v35);
              }
              result = 0;
            }
            return result;
          case 95:
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( i1 = 0; i1 != v15; ++i1 )
            {
              if ( (((unsigned __int64)v9 >> i1) & 1) != 0 )
                print_bam_pipe_selected_reg(v12 + 216, i1);
            }
            for ( i2 = 0; i2 != v15; ++i2 )
            {
              if ( (((unsigned __int64)v9 >> i2) & 1) != 0 )
                print_bam_pipe_desc_fifo(v12 + 216, i2, 0);
              result = 0;
            }
            return result;
          case 96:
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( i3 = 0; i3 != v15; ++i3 )
            {
              if ( (((unsigned __int64)v9 >> i3) & 1) != 0 )
              {
                print_bam_pipe_selected_reg(v12 + 216, i3);
                print_bam_pipe_desc_fifo(v12 + 216, i3, 0);
              }
              result = 0;
            }
            return result;
          case 97:
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( i4 = 0; i4 != v15; ++i4 )
            {
              if ( (((unsigned __int64)v9 >> i4) & 1) != 0 )
                print_bam_pipe_selected_reg(v12 + 216, i4);
            }
            for ( i5 = 0; i5 != v15; ++i5 )
            {
              if ( (((unsigned __int64)v9 >> i5) & 1) != 0 )
                print_bam_pipe_desc_fifo(v12 + 216, i5, 0);
            }
            for ( i6 = 0; i6 != v15; ++i6 )
            {
              if ( (((unsigned __int64)v9 >> i6) & 1) != 0 )
                print_bam_pipe_desc_fifo(v12 + 216, i6, 100);
              result = 0;
            }
            return result;
          case 98:
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
            if ( !(_DWORD)v15 )
              goto LABEL_134;
            for ( i7 = 0; i7 != v15; ++i7 )
            {
              if ( (((unsigned __int64)v9 >> i7) & 1) != 0 )
              {
                print_bam_pipe_selected_reg(v12 + 216, i7);
                print_bam_pipe_desc_fifo(v12 + 216, i7, 0);
                print_bam_pipe_desc_fifo(v12 + 216, i7, 100);
              }
              result = 0;
            }
            return result;
          case 99:
            print_bam_test_bus_reg(v12 + 216, a4);
            print_bam_reg(*(_DWORD **)(v12 + 216));
            if ( (_DWORD)v15 )
            {
              v38 = 0;
              do
                print_bam_pipe_reg(*(_QWORD *)(v12 + 216), v38++);
              while ( (_DWORD)v15 != v38 );
              print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
              v39 = 0;
              do
                print_bam_pipe_selected_reg(v12 + 216, v39++);
              while ( (_DWORD)v15 != v39 );
              v40 = 0;
              do
                print_bam_pipe_desc_fifo(v12 + 216, v40++, 0);
              while ( (_DWORD)v15 != v40 );
              v41 = 0;
              do
              {
                print_bam_pipe_desc_fifo(v12 + 216, v41++, 100);
                result = 0;
              }
              while ( (_DWORD)v15 != v41 );
            }
            else
            {
LABEL_133:
              print_bam_selected_reg(v12 + 216, *(_DWORD *)(v12 + 128));
LABEL_134:
              result = 0;
            }
            break;
          default:
            v46 = &unk_292EF;
            goto LABEL_154;
        }
      }
      else
      {
        printk(&unk_29DA7, a1, v11);
        mutex_unlock(sps + 112);
        return 0xFFFFFFFFLL;
      }
    }
    else
    {
      if ( (unsigned __int8)logging_option >= 2u
        && debug_level_option
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_get_bam_debug_info__rs_3, "sps_get_bam_debug_info")) )
      {
        printk(&unk_24F08, "sps_get_bam_debug_info", a3);
      }
      if ( sps && *(_DWORD *)(sps + 288) <= 3u )
      {
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver is not ready\n", "sps_get_bam_debug_info");
        return 4294966779LL;
      }
      else
      {
        return 4294966779LL;
      }
    }
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_get_bam_debug_info__rs, "sps_get_bam_debug_info")) )
    {
      printk(&unk_292C5, "sps_get_bam_debug_info", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: device handle should not be 0\n", "sps_get_bam_debug_info");
    return 0xFFFFFFFFLL;
  }
  return result;
}
