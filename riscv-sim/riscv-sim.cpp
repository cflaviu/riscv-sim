#include "PCH.h"

namespace riscv
{
	typedef uint8_t byte;

	namespace instruction
	{
		class base
		{
		public:
//			virtual ~base() {}
		};

		namespace format
		{
			namespace base
			{
				typedef instruction::base base_;

				template <typename T, const byte op_size, const byte rd_size, const byte funct_a_size, 
							const byte rs1_size, const byte rs2_size, const byte funct_b_size>
				class r: public base_
				{
				public:
					T opcode	: op_size;
					T rd		: rd_size;
					T funct_a	: funct_a_size;
					T rs1		: rs1_size;
					T rs2		: rs2_size;
					T funct_b	: funct_b_size;

					r() {}

					template <typename opcode_t>
					r( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename rd_t, typename funct_a_t, typename rs1_t, typename rs2_t, typename funct_b_t> 
					r( const opcode_t opcode, const rd_t rd, const funct_a_t funct_a, const rs1_t rs1, const rs2_t rs2, const funct_b_t funct_b): 
						opcode( opcode),
						rd( rd),
						funct_a( funct_a),
						rs1( rs1),
						rs2( rs2),
						funct_b( funct_b)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};

				template <typename T, const byte op_size, const byte rd_size, const byte funct_a_size, 
							const byte rs1_size, const byte imm_size>
				class i: public base_
				{
				public:
					T opcode	: op_size;
					T rd		: rd_size;
					T funct_a	: funct_a_size;
					T rs1		: rs1_size;
					T imm		: imm_size;

					i() {}

					template <typename opcode_t>
					i( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename rd_t, typename funct_a_t, typename rs1_t, typename imm_t> 
					i( const opcode_t opcode, const rd_t rd, const funct_a_t funct_a, const rs1_t rs1, const imm_t imm): 
						opcode( opcode),
						rd( rd),
						funct_a( funct_a),
						rs1( rs1),
						imm( imm)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};

				template <typename T, const byte op_size, const byte rd_size, const byte funct_a_size, 
							const byte rs1_size, const byte rs2_size, const byte imm_size>
				class s: public base
				{
				public:
					T opcode	: op_size;
					T rd		: rd_size;
					T funct_a	: funct_a_size;
					T rs1		: rs1_size;
					T rs2		: rs2_size;
					T imm		: imm_size;

					s() {}

					template <typename opcode_t>
					s( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename rd_t, typename funct_a_t, typename rs1_t, typename rs2_t, typename imm_t> 
					s( const opcode_t opcode, const rd_t rd, const funct_a_t funct_a, const rs1_t rs1, const rs2_t rs2, const imm_t imm): 
						opcode( opcode),
						rd( rd),
						funct_a( funct_a),
						rs1( rs1),
						rs2( rs2),
						imm( imm)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};

				template <typename T, const byte op_size, const byte rd_size, const byte imm_size>
				class u: public base_
				{
				public:
					T opcode	: op_size;
					T rd		: rd_size;
					T imm		: imm_size;

					u() {}

					template <typename opcode_t>
					u( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename rd_t, typename imm_t> 
					u( const opcode_t opcode, const rd_t rd, const imm_t imm): 
						opcode( opcode),
						rd( rd),
						imm( imm)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};
			}

			namespace immediate
			{
				template <typename T, const byte op_size, const byte rd_size, const byte funct_size, 
							const byte rs1_size, const byte imm_a_size, const byte imm_b_size, const byte imm_c_size, const byte imm_d_size>
				class i: public base
				{
				public:
					T opcode	: op_size;
					T rd		: rd_size;
					T funct		: funct_size;
					T rs1		: rs1_size;
					T imm_a		: imm_a_size;
					T imm_b		: imm_b_size;
					T imm_c		: imm_c_size;
					T imm_d		: imm_d_size;

					template <typename opcode_t>
					i( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename rd_t, typename funct_t, typename rs1_t, typename imm_a_t, typename imm_b_t, typename imm_c_t, typename imm_d_t> 
					i( const opcode_t opcode, const rd_t rd, const funct_t funct, const rs1_t rs1, const imm_a_t imm_a, const imm_b_t imm_b, const imm_c_t imm_c, const imm_d_t imm_d): 
						opcode( opcode),
						rd( rd),
						funct( funct),
						rs1( rs1),
						imm_a( imm_a),
						imm_b( imm_b),
						imm_c( imm_c),
						imm_d( imm_d)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};

				template <typename T, const byte op_size, const byte imm_a_size, const byte imm_b_size, 
							const byte funct_size, const byte rs1_size, const byte rs2_size, const byte imm_c_size, const byte imm_d_size>
				class s: public base
				{
				public:
					T opcode	: op_size;
					T imm_a		: imm_a_size;
					T imm_b		: imm_b_size;
					T funct		: funct_size;
					T rs1		: rs1_size;
					T rs2		: rs2_size;
					T imm_c		: imm_c_size;
					T imm_d		: imm_d_size;

					template <typename opcode_t>
					s( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename imm_a_t, typename imm_b_t, typename funct_t, typename rs1_t, typename imm_c_t, typename imm_d_t> 
					s( const opcode_t opcode, const imm_a_t imm_a, const imm_b_t imm_b, const funct_t funct, const rs1_t rs1, const imm_c_t imm_c, const imm_d_t imm_d): 
						opcode( opcode),
						rd( rd),
						funct( funct),
						rs1( rs1),
						imm_a( imm_a),
						imm_b( imm_b),
						imm_c( imm_c),
						imm_d( imm_d)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};

				template <typename T, const byte op_size, const byte imm_d_size, const byte imm_a_size, const byte funct_size, 
							const byte rs1_size, const byte rs2_size, const byte imm_b_size, const byte imm_c_size>
				class sb: public base
				{
				public:
					T opcode	: op_size;
					T imm_d		: imm_d_size;
					T imm_a		: imm_a_size;
					T funct		: funct_size;
					T rs1		: rs1_size;
					T rs2		: rs2_size;
					T imm_b		: imm_b_size;
					T imm_c		: imm_c_size;

					template <typename opcode_t>
					sb( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename imm_d_t, typename imm_a_t, typename funct_t, typename rs1_t, typename rs2_t, typename imm_b_t, typename imm_c_t> 
					sb( const opcode_t opcode, const imm_d_t imm_d, const imm_a_t imm_a, const funct_t funct, const rs1_t rs1, const rs2_t rs2, const imm_b_t imm_b, const imm_c_t imm_c):
						opcode( opcode),
						rd( rd),
						imm_d( imm_d),
						imm_a( imm_a),
						funct( funct),
						rs1( rs1),
						rs1( rs2),
						imm_b( imm_b),
						imm_c( imm_c)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};

				template <typename T, const byte op_size, const byte rd_size,
							const byte imm_a_size, const byte imm_b_size, const byte imm_c_size, const byte imm_d_size>
				class u: public base
				{
				public:
					T opcode	: op_size;
					T rd		: rd_size;
					T imm_a		: imm_a_size;
					T imm_b		: imm_b_size;
					T imm_c		: imm_c_size;
					T imm_d		: imm_d_size;

					template <typename opcode_t>
					u( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename rd_t, typename imm_a_t, typename imm_b_t, typename imm_c_t, typename imm_d_t> 
					u( const opcode_t opcode, const rd_t rd, const imm_a_t imm_a, const imm_b_t imm_b, const imm_c_t imm_c, const imm_d_t imm_d): 
						opcode( opcode),
						rd( rd),
						imm_a( imm_a),
						imm_b( imm_b),
						imm_c( imm_c),
						imm_d( imm_d)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};

				template <typename T, const byte op_size, const byte rd_size,
							const byte imm_d_size, const byte imm_e_size, const byte imm_c_size,
							const byte imm_a_size, const byte imm_b_size, const byte imm_f_size>
				class uj: public base
				{
				public:
					T opcode	: op_size;
					T rd		: rd_size;
					T imm_d		: imm_d_size;
					T imm_e		: imm_e_size;
					T imm_c		: imm_c_size;
					T imm_a		: imm_a_size;
					T imm_b		: imm_b_size;
					T imm_f		: imm_f_size;

					template <typename opcode_t>
					uj( const opcode_t opcode): opcode( op) {}

					template <typename opcode_t, typename rd_t, typename imm_d_t, typename imm_e_t, typename imm_c_t, typename imm_a_t, typename imm_b_t, typename imm_f_t> 
					uj( const opcode_t opcode, const rd_t rd, const imm_d_t imm_d, const imm_e_t imm_e, const imm_c_t imm_c, const imm_a_t imm_a, const imm_b_t imm_b, const imm_f_t imm_f): 
						opcode( opcode),
						rd( rd),
						imm_d( imm_d),
						imm_e( imm_e),
						imm_c( imm_c),
						imm_a( imm_a),
						imm_b( imm_b),
						imm_f( imm_f)
					{}

					void operator = ( const T value)
					{
						*reinterpret_cast<T*>( &opcode) = value;
					}
				};
			}
		}

		namespace rv32
		{
			namespace base
			{
				namespace fb = format::base;
				typedef fb::r<uint32_t, 7, 5, 3, 5, 5, 7>	r;
				typedef fb::i<uint32_t, 7, 5, 3, 5, 12>		i;
				typedef fb::s<uint32_t, 7, 5, 3, 5, 5, 7>	s;
				typedef fb::u<uint32_t, 7, 5, 20>			u;
			}

			namespace immediate
			{
				namespace fi = format::immediate;
				typedef fi::i<uint32_t, 7, 5, 3, 5, 1, 4, 6, 1>		i;
				typedef fi::s<uint32_t, 7, 1, 4, 3, 5, 5, 6, 1>		s;
				typedef fi::sb<uint32_t, 7, 1, 4, 3, 5, 5, 6, 1>	sb;
				typedef fi::u<uint32_t, 7, 5, 3, 5, 11, 1>			u;
				typedef fi::uj<uint32_t, 7, 5, 3, 5, 1, 4, 6, 1>	uj;
			}

			namespace funct3
			{
				enum item
				{
					add,
					addi,
					and,
					andi,
					or,
					ori,
					sll,
					slli,
					slt,
					slti,
					sltiu,
					sltu,
					sra,
					srai,
					srl,
					srlli,
					sub,
					xor,
					xori,

					COUNT_
				};
			}

			namespace funct5
			{
				enum item
				{
					fadd,
					fsub,
					fmul,
					fdiv,
					fmin_max,
					fsqrt,
					fcvt,
					fsgnj,
					fmv,
					fmvx,
					fcmp,

					COUNT_
				};
			}

			namespace funct12
			{
				enum item
				{
					muldiv,

					COUNT_
				};
			}

			namespace opcode
			{
				enum item
				{
					lui,
					auipc,
					jal,
					jar,
					op_imm,
					load,
					store,
					load_fp,
					store_fp,

					COUNT_
				};
			}
		}

		namespace branch
		{
			//typedef int mul;

			class beq: public base
			{
			public:
			};

			class bne: public base
			{
			public:
			};

			class blt: public base
			{
			public:
			};

			class bge: public base
			{
			public:
			};

			class bltu: public base
			{
			public:
			};

			class bgeu: public base
			{
			public:
			};

			class lui: public base
			{
			public:
			}; 

			class auipc: public base
			{
			public:
			};

			class jal: public base
			{
			public:
			};

			class jalr: public base
			{
			public:
			};
		}

		namespace load_store
		{
			class lb: public base
			{
			public:
			};

			class lh: public base
			{
			public:
			};

			class lbu: public base
			{
			public:
			};

			class lhu: public base
			{
			public:
			};

			class lw: public base
			{
			public:
			};

			// new
			class ldrd: public base
			{
			public:
			};

			class sb: public base
			{
			public:
			};

			class sh: public base
			{
			public:
			};

			class sw: public base
			{
			public:
			};

			// new - ldr postmod
			class ldr: public base
			{
			public:
			};

			// new - str postmod
			class str: public base
			{
			public:
			};
		}

		namespace integer
		{
			class add: public base
			{
			public:
			};

			class addi: public base
			{
			public:
			};

			class slti: public base
			{
			public:
			};

			class sltiu: public base
			{
			public:
			};

			class bltu: public base
			{
			public:
			};

			class bgeu: public base
			{
			public:
			};

			class lui: public base
			{
			public:
			};

			class auipc: public base
			{
			public:
			};

			class jal: public base
			{
			public:
			};

			class jalr: public base
			{
			public:
			};
		}

		class decoder
		{
		};

		class queue
		{
		};
	}

	namespace register_
	{
		class base
		{
		public:
			virtual ~base() {}
		};

		template <typename T>
		class r: public base
		{
		};

		typedef r<uint16_t> r16;
		typedef r<uint32_t> r32;
		typedef r<uint64_t> r64;

		class r128: public base
		{
		public:
			virtual ~r128() {}
		};

		namespace vector
		{
			class base
			{
			public:
				virtual ~base() {}
			};

			template <typename T, const uint8_t size>
			class r: public base
			{
			};

			template <const uint8_t size>
			using r16 = r<uint16_t, size>;

			template <const uint8_t size>
			using r32 = r<uint32_t, size>;

			template <const uint8_t size>
			using r64 = r<uint64_t, size>;
		}
	}

	namespace unit
	{
		class base
		{
		public:
			virtual ~base() {}
		};

		// arithmetic logic unit
		namespace alu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// fixed-point execution unit
		namespace fxu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// fixed-point execution unitfixed-point execution unit
		namespace fpu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// address generation unit
		namespace agu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		namespace branch_prediction
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// memory management unit
		namespace mmu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// translation lookaside buffer
		namespace tlb
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// memory interface unit
		namespace miu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// memory order buffer
		namespace mob
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		namespace cache
		{
			class base
			{
			public:
				virtual ~base() {}
			};

			namespace instruction
			{
				class base
				{
				public:
					virtual ~base() {}
				};
			}

			namespace data
			{
				class base
				{
				public:
					virtual ~base() {}
				};
			}

			namespace unified
			{
				class base
				{
				public:
					virtual ~base() {}
				};
			}
		}

		namespace scheduler
		{
			class base
			{
			public:
				virtual ~base() {}
			};
		}

		namespace simd
		{
			class base: public unit::base
			{
			public:
			};

			// SIMD ALU
			class alu: public base
			{
			public:
				virtual ~alu() {}
			};

			// SIMD FPU
			class fpu: public base
			{
			public:
				virtual ~fpu() {}
			};
		}
	}

	namespace memory
	{
		class base
		{
		public:
			virtual ~base() {}
		};
	}

	namespace cpu
	{
		class base
		{
		public:
			virtual ~base() {}
		};

		namespace scalar
		{
			class base: public cpu::base
			{
			public:
				virtual ~base() {}
			};

			class s1: public base
			{
			public:
			};
		}

		namespace superscalar
		{
			class base: public cpu::base
			{
			public:
				virtual ~base() {}
			};

			class s1: public base
			{
			public:
			};
		}
	}

	namespace simulator
	{
		class base
		{
		public:
			virtual ~base() {}
		};

		namespace scalar
		{
			template <typename cpu_t, const uint8_t cpu_count>
			class t1: public base
			{
			};

			template <const uint8_t size>
			using s1 = t1<cpu::scalar::s1, size>;

			typedef s1<1> single_core1;
			typedef s1<2> dual_core1;
			typedef s1<4> quad_core1;
		}

		namespace superscalar
		{
			template <typename cpu_t, const uint8_t cpu_count>
			class t1: public base
			{
			};

			template <const uint8_t size>
			using s1 = t1<cpu::superscalar::s1, size>;

			typedef s1<1> single_core1;
			typedef s1<2> dual_core1;
			typedef s1<4> quad_core1;
			typedef s1<8> octa_core1;
		}
	}
}

int main()
{
	using namespace riscv;
	simulator::superscalar::quad_core1 simulator;

//	int x = sizeof(instruction::format::r);

	return 0;
}
