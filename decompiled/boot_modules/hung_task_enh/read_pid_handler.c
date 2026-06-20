__int64 __fastcall read_pid_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  mutex_lock(&readpid_mutex);
  LODWORD(a5) = proc_dointvec_minmax(a1, a2, a3, a4, a5);
  mutex_unlock(&readpid_mutex);
  return (unsigned int)a5;
}
